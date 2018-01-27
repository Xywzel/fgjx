#include "Level.h"

#include "SDL2/SDL.h"

#include "Utils.h"

Level::Level()
	: completed(false)
	, failed(false)
	, pause(false)
{
}

Level::~Level()
{
	if(background.ready)
	{
		background.free();
	}
}

void Level::handleEvent(SDL_Event& e)
{
	if(e.type == SDL_KEYDOWN)
	{
		switch(e.key.keysym.sym)
		{
			case SDLK_ESCAPE:
				pause = true;
			default:
				break;
		}
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
  bool val = pause;
  pause = false;
  return val;
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
		background.init(renderer, "background.png");
	}
	background.render(0,0);
}

