#pragma once

#include <SDL2/SDL.h>

class Game
{
	public:
		Game();
		~Game();
		bool init();
		void run();
	private:
		SDL_Window* window = NULL;
		SDL_Surface* surface = NULL;

		const char* gameTitle = "The Game";
		const int screenWidth = 640;
		const int screenHeight = 480;
};
