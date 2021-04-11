#ifndef _state_manager_h
#define _state_manager_h

#include "state_game.h"

#define STATES_MAX_NUM 256

typedef struct state_manager_t state_manager_t;

struct state_manager_t
{
	state_t *states[STATES_MAX_NUM];
	int index;
};

state_manager_t* state_manager_create();
void state_manager_destroy(state_manager_t *state_manager);

void state_manager_push(state_manager_t *state_manager, state_t *state);
void state_manager_pop(state_manager_t *state_manager);
state_t* state_manager_top(state_manager_t *state_manager);

#endif
