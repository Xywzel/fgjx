#include "Level.h"
#include "Utils.h"

Level::Level()
{
}

Level::~Level()
{
    SDL_DestroyTexture(background);
}

void Level::update()
{}

int Level::getScoreIncrease(){
return 0;
}

bool menuOpened(){
    return false;
}

bool finished(){
    return false;
}

bool isGameOver(){
    return false;
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
