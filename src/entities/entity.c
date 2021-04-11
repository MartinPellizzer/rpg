#include "entity.h"


entity_t* entity_create()
{
	entity_t *entity = (entity_t*)malloc(sizeof(entity_t));
	if(entity == NULL) return NULL;

	entity->x = 50;
	entity->y = 50;
	entity->speed = 100;
	entity->shape.x = entity->x;
	entity->shape.y = entity->y;
	entity->shape.w = 50;
	entity->shape.h = 50;

	entity->child = entity;
	entity->destroy = entity_destroy;
	entity->update = entity_update;
	entity->render = entity_render;
	
	return entity;
}

void entity_destroy(entity_t* entity)
{
}

void entity_update(entity_t* entity, float dt)
{
	const Uint8 *keystate = SDL_GetKeyboardState(NULL);
	if(keystate[SDL_SCANCODE_W])
		entity_move(entity, dt, 0, -1);
	if(keystate[SDL_SCANCODE_S])
		entity_move(entity, dt, 0, 1);
	if(keystate[SDL_SCANCODE_A])
		entity_move(entity, dt, -1, 0);
	if(keystate[SDL_SCANCODE_D])
		entity_move(entity, dt, 1, 0);
}

void entity_render(entity_t* entity, SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &entity->shape);
}

void entity_move(entity_t* entity, float dt, float dir_x, float dir_y)
{
	entity->x += dir_x * entity->speed * dt;
	entity->y += dir_y * entity->speed * dt;

	entity->shape.x = (int)(entity->x);
	entity->shape.y = (int)(entity->y);
}
