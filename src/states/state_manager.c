#include "state_manager.h"

state_manager_t* state_manager_create()
{
	state_manager_t *state_manager = (state_manager_t*)malloc(sizeof(state_manager_t));
	if(state_manager == NULL) return NULL;

	for(int i = 0; i < STATES_MAX_NUM; i++)
		state_manager->states[i] = NULL;

	state_manager->index = -1;

	return state_manager;
}

void state_manager_destroy(state_manager_t *state_manager)
{
	while(state_manager->index > -1)
	{
		state_manager_pop(state_manager);
		printf("%d\n", state_manager->index);
	}

	if(state_manager != NULL)
	{
		free(state_manager);
		state_manager = NULL;
	}
}

void state_manager_push(state_manager_t *state_manager, state_t *state)
{
	if(state_manager->index >= STATES_MAX_NUM) return;

	state_manager->index++;
	state_manager->states[state_manager->index] = state;
}

void state_manager_pop(state_manager_t *state_manager)
{
	if(state_manager->index < 0) return;
	
	state_t *state_curr = state_manager->states[state_manager->index];
	state_curr->destroy(state_curr);
	state_manager->index--;
}

state_t* state_manager_top(state_manager_t *state_manager)
{
	if(state_manager->index < 0) return NULL;

	return state_manager->states[state_manager->index];
}

