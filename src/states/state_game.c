#include "state_game.h"

state_t* state_game_create()
{
	state_t *state = state_create();
	if(state == NULL) return NULL;

	state_game_t *state_game = (state_game_t*)malloc(sizeof(state_game_t));
	if(state_game == NULL) return NULL;

	state->child = state_game;
	state->quit = 0;
	state->destroy = state_game_destroy;

	state->update_input = state_game_update_input;
	state->update = state_game_update;
	state->render = state_game_render;

	state_game->entity = entity_create();

	return state;
}

void state_game_destroy(state_t *state)
{
	if(state->child != NULL)
	{
		free(state->child);
		state->child = NULL;
	}
	
	state_destroy(state);

	printf("STATE: GAME -> Destroyed!!\n");
}



void state_game_update_input(state_t *state)
{

	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						state->quit = 1;
						break;
					default:
						break;
				}
				break;
			
			default:
				break;
		}
	}
	
}

void state_game_update(state_t *state, float dt)
{
	state->update_input(state);

	entity_t *entity = ((state_game_t*)state->child)->entity;
	entity->update(entity, dt);
}

void state_game_render(state_t *state, SDL_Renderer *renderer)
{
	entity_t *entity = ((state_game_t*)state->child)->entity;
	entity->render(entity, renderer);
}

