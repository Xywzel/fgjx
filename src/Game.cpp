#include "Game.h"

#include <iostream>
#include <SDL2/SDL.h>

Game::Game()
{

}

Game::~Game(){}

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

	return true;
}

void Game::run()
{
	SDL_Delay(2000);
}
