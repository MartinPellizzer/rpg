#include "../inc/sprite.h"

void sprite_init(sprite_t *sprite, SDL_Renderer *renderer, char *path, SDL_Rect srcRect, SDL_Rect dstRect)
{
	sprite->renderer = renderer;
	sprite->texture = IMG_LoadTexture(renderer, path);

	sprite->srcRect.x = srcRect.x;
	sprite->srcRect.y = srcRect.y;
	sprite->srcRect.w = srcRect.w;
	sprite->srcRect.h = srcRect.h;

	sprite->dstRect.x = dstRect.x;
	sprite->dstRect.y = dstRect.y;
	sprite->dstRect.w = dstRect.w;
	sprite->dstRect.h = dstRect.h;
}

void sprite_deinit(sprite_t *sprite)
{
	SDL_DestroyTexture(sprite->texture);
}

void sprite_render(sprite_t *sprite)
{
	SDL_RenderCopy(sprite->renderer, sprite->texture, &sprite->srcRect, &sprite->dstRect);
}

void sprite_move(sprite_t *sprite, int x, int y)
{
	sprite->dstRect.x += x;
	sprite->dstRect.y += y;
}



