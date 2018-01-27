#include "Level.h"
#include "Utils.h"

Level::Level()
{
}

Level::~Level()
{
	SDL_DestroyTexture(background);
}

void Level::update(float deltaTime)
{
	(void)deltaTime;
}

int Level::getScoreIncrease(){
return 0;
}

bool Level::menuOpened(){
    return false;
}

bool Level::finished(){
    return false;
}

bool Level::isGameOver(){
    return false;
}

void Level::render(SDL_Renderer* renderer)
{
	if(background == NULL)
	{
		SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
		background = Utils::LoadTexture("troll.bmp", renderer);
	}
}

