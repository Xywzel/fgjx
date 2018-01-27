#pragma once

#include <SDL2/SDL.h>

#include "Input.h"
#include "Level.h"

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
		SDL_Event e;
		Level level;
		bool running;

		const char* gameTitle = "The Game";
		const int screenWidth = 640;
		const int screenHeight = 480;

		bool keysDown[Input::KeyCount] = {false};

		void getEvents();
		void update();
		void render();
};
