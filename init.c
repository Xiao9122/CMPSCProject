/*
 * s_sdl.c
 * 
 * Initializes SDL
 */


#include <stdio.h>
#include "defs.h"
#include "structs.h"

extern Game game;

void SDLInit(void)
{
	int rendererFlags;
	int windowFlags;
	
	rendererFlags = SDL_RENDERER_ACCELERATED;
	windowFlags = 0;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("ERROR; SDL couldn't initialize: %s\n", SDL_GetError());
		exit(1);
	}

	if (SDL_Init(SDL_INIT_TIMER) != 0)
	{
		printf("ERROR; SDL couldn't initialize: %s\n", SDL_GetError());
		exit(1);
	}
	
	game.window = SDL_CreateWindow("CMPSC Project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (!game.window)
	{
		printf("ERROR; SDL couldn't initialize: %s\n", SDL_GetError());
		exit(1);
	}

	game.renderer = SDL_CreateRenderer(game.window, -1, rendererFlags);

	if (!game.renderer)
	{
		printf("ERROR; SDL couldn't initialize: %s\n", SDL_GetError());
		exit(1);
	}
}

void SDLQuit(void)
{
	SDL_DestroyRenderer(game.renderer);
	SDL_DestroyWindow(game.window);
	SDL_Quit();
}
