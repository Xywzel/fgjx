#include "MainMenu.h"
#include <SDL2/SDL.h>

MainMenu::MainMenu()
	: highlighted(None)
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::render(SDL_Renderer* renderer)
{

}

void MainMenu::update()
{
	
}

bool MainMenu::shouldStart()
{
	return open;
}


