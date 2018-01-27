#pragma once

#include <SDL2/SDL.h>

#include "Input.h"
#include "Level.h"

class State;
class Game
{
	public:
		Game();
		~Game();
		bool init();
		void run();
	private:
		State* state = NULL;
		SDL_Window* window = NULL;
		SDL_Surface* surface = NULL;
		SDL_Renderer* renderer = NULL;
		SDL_Event e;
		Level level;
		bool running;
		uint32_t startTime;
		uint32_t lastTime;

		const char* gameTitle = "The Game";
		const int screenWidth = 1280;
		const int screenHeight = 800;

		bool keysDown[Input::KeyCount] = {false};

		void getEvents();
		void update();
		void render();
};
