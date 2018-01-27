#include "Menu.h"
#include <SDL2/SDL.h>

Menu::Menu()
	: open(false)
{
}

Menu::~Menu()
{
}

void Menu::handleEvent(SDL_Event& /*e*/)
{
}

bool Menu::isOpen()
{
	return open;
}

void Menu::show(int /*arg*/)
{
	open = true;
}
