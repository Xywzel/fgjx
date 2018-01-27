#include "Level.h"
#include "Utils.h"

Level::Level()
	: completed(false)
	, failed(false)
{
}

Level::~Level()
{
	if(background.ready)
	{
		background.free();
	}
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
    return completed;
}

bool Level::isGameOver(){
    return failed;
}

void Level::render(SDL_Renderer* renderer)
{
	if(!background.ready)
	{
		SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
		background.init(renderer, "background.png");
	}
	background.render(0,0);
}

