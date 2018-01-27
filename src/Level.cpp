#include "Level.h"

#include "SDL2/SDL.h"

#include "Utils.h"

Level::Level()
	: completed(false)
	, failed(false)
	, pause(false)
{
	player.setXY(50, 50);
	message = "No fucking clue.";
}

Level::~Level()
{

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
		background.init(renderer, "board.png");
	}
	background.render(0,0, 1.0f, 1.0f);
	player.render(renderer);
}

