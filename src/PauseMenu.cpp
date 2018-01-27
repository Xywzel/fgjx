#include "PauseMenu.h"
#include <SDL2/SDL.h>

PauseMenu::PauseMenu()
{
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::render(SDL_Renderer* renderer)
{
}

void PauseMenu::update()
{
}

void PauseMenu::show(int arg)
{
	score =  arg;
	Menu::show();
}

bool PauseMenu::shouldExit()
{
	return !open;
}
