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
	ctx = tsMakeContext(0, 44000, 15, 5, 5);
	loaded = tsLoadWAV( "path_to_file/filename.wav" );
	def = tsMakeDef( &loaded );
}

Level::~Level()
{
	tsShutdownContext(ctx);
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
	tsPlayingSound* sound = tsPlaySound( ctx, def );
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
	background.render(0,0, 1.0f, 1.0f);
	player.render(renderer);
}

