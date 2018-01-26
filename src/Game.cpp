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
		std::cout << "Error: SDL_ could not be initialized. SDL_Error" << SDL_GetError() << std::endl;
		return false;
	}
	window = SDL_CreateWindow(gameTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

	return true;
}

void Game::run()
{
}
