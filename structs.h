/*
 * s_structs.h
 *
 * General program structs
 */

#include <SDL2/SDL.h>

typedef struct
{
	SDL_Renderer *renderer;
	SDL_Window *window;
} Game;

typedef struct
{
	float x;
	float y;
} Vector2;

typedef struct
{
	SDL_Texture *texture;
	SDL_Rect rect;
	Vector2 location;
	Vector2 dimensions;
	Vector2 origin;
	float rotation;
} Sprite;
