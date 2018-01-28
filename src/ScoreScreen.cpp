#include "ScoreScreen.h"

#include <SDL2/SDL.h>

ScoreScreen::ScoreScreen()
	: score(0)
{
}

ScoreScreen::~ScoreScreen()
{
}

void ScoreScreen::render(SDL_Renderer* renderer)
{
	if(!background.ready) background.init(renderer, "background.png");
	if(!victory.ready) victory.init(renderer, "victory.png");
	if(!loose.ready) loose.init(renderer, "loose.png");
	background.render(0.0f, 0.0f, 1.0f, 1.0f);
	if (score > 0)
		victory.render(0.3f, 0.3f, 0.4f, 0.4f);
	else
		loose.render(0.3f, 0.3f, 0.4f, 0.4f);
}

void ScoreScreen::handleEvent(SDL_Event& e)
{
	if(e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
			case SDLK_ESCAPE:
			case SDLK_RETURN:
			case SDLK_SPACE:
				open = false;
		}
	}
}

void ScoreScreen::update()
{
}

void ScoreScreen::show(int arg)
{
	score = arg;
	Menu::show();
}
