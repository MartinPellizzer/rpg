#ifndef _game_h
#define _game_h

#include "../src/states/state_manager.h"

typedef struct game_t
{
	int is_running;

	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;

	float dt_prev;
	float dt;

	state_manager_t *state_manager;
} game_t;

void game_init(game_t *game);
void game_deinit(game_t *game);

void game_update_dt(game_t *game);
void game_update(game_t *game);

void game_render(game_t *game);

void game_run(game_t *game);

#endif
