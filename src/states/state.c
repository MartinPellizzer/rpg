#include "state.h"

state_t* state_create()
{
	state_t *state = (state_t*)malloc(sizeof(state_t));
	if(state == NULL) return NULL;

	state->child = NULL;
	state->quit = 0;

	state->destroy = NULL;
	state->update_input = NULL;
	state->update = NULL;
	state->render = NULL;

	state->end = NULL;

	return state;
}

void state_destroy(state_t *state)
{
	if(state != NULL)
	{
		free(state);
		state = NULL;
	}
}

