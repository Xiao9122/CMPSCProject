/*
 * g_main.c
 * 
 * Main game loop
 */

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "structs.h"

extern SDL_Texture* LoadTexture(char *filename);
extern void SDLInit(void);
extern void Draw(Sprite sprite, bool centered);
extern void ClearBuffer(void);
extern void PresentBuffer(void);
extern void EventInput(void);

Game game;
Sprite player;

int main(int argc, char *argv[])
{
	SDLInit();
	player.texture = LoadTexture("resources/ship.png");
	player.location.x = 100;
	player.location.y = 100;
	player.dimensions.x = 64;
	player.dimensions.y = 64;
	while (true)
	{
		ClearBuffer();
		EventInput();
		Draw(player, true);
		PresentBuffer();
		SDL_Delay(16);
	}
	return 0;
}
