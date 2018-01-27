#include "Menu.h"

Menu::Menu()
	: open(false)
{
}

Menu::~Menu()
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
