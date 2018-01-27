#include "Game.h"

#include <iostream>
#include <SDL2/SDL.h>
#include "Input.h"

Game::Game()
	: running(true)
{

}

Game::~Game()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
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

    imageSurface = SDL_LoadBMP( "troll.bmp" );
    if( imageSurface == NULL )
    {
        std::cout <<  "Unable to load image!" <<  SDL_GetError() << std::endl;
    }
    else
    {
        optimizedSurface = SDL_ConvertSurface(imageSurface, surface->format, NULL);
        if (optimizedSurface == NULL)
        {
            std::cout << "Unable to optimize image! << SDL_GetError()" << std::endl;
        }
        SDL_FreeSurface(imageSurface);
    }
	return true;
}

void Game::run()
{
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
		else if(e.type == SDL_KEYDOWN)
		{
			Input::Key key = Input::getKeyFromEvent(e);
			keysDown[(int) key] = true;
		}
	}
}

void Game::update()
{
	if(keysDown[(int) Input::Key::Esc]) running = false;

}

void Game::render()
{
    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.w = screenWidth;
    stretchRect.h = screenHeight;
    SDL_BlitScaled( optimizedSurface, NULL, surface, &stretchRect );
	//SDL_BlitSurface(optimizedSurface, NULL, surface, NULL);
	SDL_UpdateWindowSurface(window);

}

