#include <SDL2/SDL.h>

extern void SDLQuit(void);

void EventInput(void)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				SDLQuit();
				exit(0);
				break;
			default:
				break;
		}
	}
}
