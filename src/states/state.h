#ifndef _state_h
#define _state_h

#include "../entities/entity.h"

typedef struct state_t state_t;

struct state_t
{
	void *child;

	int quit;

	void (*destroy)(state_t *state);
	void (*update_input)(state_t *state);
	void (*update)(state_t *state, float dt);
	void (*render)(state_t *state, SDL_Renderer *renderer);

	void (*end)(state_t *state);
};

state_t* state_create();

void state_destroy(state_t *state);
void state_update_input(state_t *state);
void state_update(state_t *state, float dt);
void state_render(state_t *state, SDL_Renderer *renderer);

#endif
