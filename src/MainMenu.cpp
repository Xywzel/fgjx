#include "MainMenu.h"
#include <SDL2/SDL.h>
#include <iostream>

MainMenu::MainMenu()
	: highlighted(None)
	, background()
	, buttonStart()
	, buttonQuit()
	, selection()
	, start(false)
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::render(SDL_Renderer* renderer)
{
	if(!intro.ready) intro.init(renderer, "intro.png");
	if(!background.ready) background.init(renderer, "background.png");
	if(!buttonStart.ready) buttonStart.init(renderer, "start.png");
	if(!buttonQuit.ready) buttonQuit.init(renderer, "quit.png");
	if(!selection.ready) selection.init(renderer, "select.png");
	background.render(0.0f, 0.0f, 1.0f, 1.0f);
	intro.render(0.3f, 0.0f, 0.4f, 0.2f);
	buttonStart.render(0.3f, 0.3f, 0.4f, 0.2f);
	buttonQuit.render(0.3f, 0.6f, 0.4f, 0.2f);
	if(highlighted == StartButton)
		selection.render(0.1f, 0.3f, 0.3f, 0.2f);
	else
		selection.render(0.1f, 0.6f, 0.3f, 0.2f);
}

void MainMenu::handleEvent(SDL_Event& event)
{
	if(event.type == SDL_KEYDOWN)
	{
		switch(event.key.keysym.sym)
		{
			case SDLK_UP:
			case SDLK_w:
				highlighted = StartButton;
				break;
			case SDLK_DOWN:
			case SDLK_s:
				highlighted = QuitButton;
				break;
			case SDLK_SPACE:
			case SDLK_RETURN:
			case SDLK_KP_ENTER:
				{
					if(highlighted == StartButton)
						start = true;
					open = false;
					break;
				}
			default:
				break;
		}
	}
}

void MainMenu::update()
{
	
}

bool MainMenu::shouldStart()
{
	bool val = start;
	start = false;
	return val;
}


