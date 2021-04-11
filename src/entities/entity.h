#ifndef _entity_h 
#define _entity_h 

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

typedef struct entity_t entity_t;

struct entity_t
{
	SDL_Rect shape;
	float speed;
	float x;
	float y;
	
	void *child;
	void (*destroy)(entity_t* entity);
	void (*update)(entity_t* entity, float dt);
	void (*render)(entity_t* entity, SDL_Renderer *renderer);
	void (*move)(entity_t* entity, float dt, float dir_x, float dir_y);
};

entity_t* entity_create();

void entity_destroy(entity_t* entity);
void entity_update(entity_t* entity, float dt);
void entity_render(entity_t* entity, SDL_Renderer *renderer);
void entity_move(entity_t* entity, float dt, float dir_x, float dir_y);

#endif
