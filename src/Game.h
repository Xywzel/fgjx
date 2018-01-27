#pragma once

#include <SDL2/SDL.h>

#include "Input.h"

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
        SDL_Surface* imageSurface = NULL;
        SDL_Surface* optimizedSurface = NULL;
		SDL_Event e;
		SDL_Rect stretchRect;
		bool running;

		const char* gameTitle = "The Game";
		const int screenWidth = 640;
		const int screenHeight = 480;

		bool keysDown[Input::KeyCount] = {false};

		void getEvents();
		void update();
		void render();
};
