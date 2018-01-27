#include "Game.h"

#include <iostream>
#include <SDL2/SDL.h>
#include "Input.h"
#include "State.h"

Game::Game()
	: running(true)
	, startTime(0)
{
	state = new State();
}

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	delete state;
}

bool Game::init()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Error: SDL could not be initialized. SDL_Error " << SDL_GetError() << std::endl;
		return false;
	}
	window = SDL_CreateWindow(gameTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	if(!window)
	{
		std::cout << "Error: SDL could not create window, SDL_Error " << SDL_GetError() << std::endl;
		return false;
	}
	surface = SDL_GetWindowSurface(window);
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(window);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	return true;
}

void Game::run()
{
	startTime = SDL_GetTicks();
	lastTime = startTime;
	while (running)
	{
		getEvents();
		update();
		render();
		SDL_Delay(60);
	}
}

void Game::getEvents()
{
	while (SDL_PollEvent(&e) != 0)
	{
		if(e.type == SDL_QUIT)
		{
			running = false;
		}
		else if (e.type == SDL_KEYDOWN)
		{
			state->handleEvent(e);
		}
	}
}

void Game::update()
{
	uint32_t currentTime = SDL_GetTicks();
	float dt = (float) (lastTime - currentTime) / 1000.0f;
	lastTime = currentTime;

	state->update(dt);
	if(state->gameOver())
	{
		running = false;
	}
}

void Game::render()
{
	state->render(renderer);
	SDL_UpdateWindowSurface(window);
}

