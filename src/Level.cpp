#include "Level.h"
#include "Utils.h"

Level::Level()
{
}

Level::~Level()
{
	SDL_DestroyTexture(background);
}

void Level::render(SDL_Window* window)
{
	if(background == NULL)
	{
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);	
		if(renderer == NULL)
		{
			std::cout << "Renderer could not be created!" << SDL_GetError() << std::endl;
			return;
		}
		SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
		background = Utils::LoadTexture("troll.bmp", renderer);
		if (background == NULL)
		{
			
		}
	}
}

void Level::update(float deltaTime)
{

}
