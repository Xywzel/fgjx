#include "Level.h"
#include "Utils.h"

Level::Level()
	: completed(false)
	, failed(false)
{
	player.setXY(50, 50);
	message = "No fucking clue.";
}

Level::~Level()
{

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
		background.init(renderer, "background.png");
	}
	background.render(0,0);
	player.render(renderer);
}

