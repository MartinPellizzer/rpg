#ifndef _sprite_h
#define _sprite_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct sprite_t
{
	SDL_Texture *texture;
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	SDL_Renderer *renderer;
} sprite_t;

void sprite_init(sprite_t *sprite, SDL_Renderer *renderer, char *path, SDL_Rect srcRect, SDL_Rect dstRect);
void sprite_deinit(sprite_t *sprite);
void sprite_render(sprite_t *sprite);

void sprite_move(sprite_t *sprite, int x, int y);

#endif
