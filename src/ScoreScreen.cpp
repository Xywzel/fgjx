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
}

void ScoreScreen::update()
{
}

void ScoreScreen::show(int arg)
{
	score = arg;
	Menu::show();
}
