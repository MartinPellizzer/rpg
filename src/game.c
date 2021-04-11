#include "../inc/game.h"


static int sdl_init(game_t *game)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read = 0;

	fp = fopen("./config/window.ini", "r");
	if(fp == NULL)
	{
		printf("cant open file\n");
		return 0;
	}
	
	read = getline(&line, &len, fp);
	char window_title[read - 1];
	for(int i = 0; i < read - 1; i++)
		window_title[i] = line[i];

	int window_width = 800;	
	read = getline(&line, &len, fp);
	window_width = atoi(line);

	int window_height = 600;	
	read = getline(&line, &len, fp);
	window_height = atoi(line);

	fclose(fp);

	game->window = SDL_CreateWindow(window_title, 100, 100, window_width, window_height, SDL_WINDOW_SHOWN);
	if(!game->window)
	{
		printf("Cant create window");
		return 0;
	}

	game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
	if(!game->renderer)
	{
		printf("Cant create renderer");
		return 0;
	}
	
	return 1;
}

static void game_init_states(game_t* game)
{
	game->state_manager = state_manager_create();

	state_t* state_game2 = state_game_create();
	state_manager_push(game->state_manager, state_game2);

}

void game_init(game_t *game)
{
	game->is_running = sdl_init(game);
	game_init_states(game);

	game->dt = 0;
	game->dt_prev = 0;
}

void game_deinit(game_t *game)
{
	state_manager_destroy(game->state_manager);

	SDL_DestroyRenderer(game->renderer);
	SDL_DestroyWindow(game->window);
	SDL_Quit();
}

void game_run(game_t *game)
{
	while(game->is_running)
	{
		game_update_dt(game);
		game_update(game);
		game_render(game);
	}
}

void game_update_dt(game_t *game)
{
	game->dt = (SDL_GetTicks() - game->dt_prev) / 1000.0;
	game->dt_prev = SDL_GetTicks();
}

void game_update(game_t *game)
{
	state_t *state_curr = state_manager_top(game->state_manager);
	if(state_curr != NULL)
	{
		state_curr->update(state_curr, game->dt);
		if(state_curr->quit == 1)
		{
			state_manager_pop(game->state_manager);
		}
	}
	else
	{
		game->is_running = 0;
	}

	SDL_Delay(1);
}

void game_render(game_t *game)
{
	SDL_SetRenderDrawColor(game->renderer, 191, 191, 191, 255);
	SDL_RenderClear(game->renderer);

	state_t *state_curr = state_manager_top(game->state_manager);
	if(state_curr != NULL)
		state_curr->render(state_curr, game->renderer);

	SDL_RenderPresent(game->renderer);
}


