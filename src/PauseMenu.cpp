#include "PauseMenu.h"
#include <SDL2/SDL.h>

PauseMenu::PauseMenu()
	: current(MenuButton)
{
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::render(SDL_Renderer* renderer)
{
	//if(!background.ready) background.init(renderer, "pauseBackground.png");
	if(!menuButton.ready) menuButton.init(renderer, "menu.png");
	if(!continueButton.ready) continueButton.init(renderer, "continue.png");
	if(!selection.ready) selection.init(renderer, "select.png");
	//background.render(0.0f, 0.0f, 1.0f, 1.0f);
	menuButton.render(0.3f, 0.2f, 0.4f, 0.2f);
	continueButton.render(0.3f, 0.6f, 0.4f, 0.2f);
	if(current == MenuButton)
		selection.render(0.1f, 0.2f, 0.3f, 0.2f);
	else
		selection.render(0.1f, 0.6f, 0.3f, 0.2f);
}

void PauseMenu::handleEvent(SDL_Event& e)
{
	if(e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
			case SDLK_UP:
			case SDLK_w:
				current = MenuButton;
				break;
			case SDLK_DOWN:
			case SDLK_s:
				current = ContinueButton;
				break;
			case SDLK_SPACE:
			case SDLK_RETURN:
			case SDLK_KP_ENTER:
				{
					open = false;
					break;
				}
			default:
				break;
		}
	}
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
	return !open && (current == MenuButton);
}
