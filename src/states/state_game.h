#ifndef _state_game_h
#define _state_game_h

#include "state.h"

typedef struct state_game_t state_game_t;

struct state_game_t
{
	entity_t *entity;
};

state_t* state_game_create();
void state_game_destroy(state_t *state);

void state_game_update_input(state_t *state);
void state_game_update(state_t *state, float dt);

void state_game_render(state_t *state, SDL_Renderer *renderer);

void state_game_end(state_t *state);

#endif
