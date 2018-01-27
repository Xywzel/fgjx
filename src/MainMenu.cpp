#include "MainMenu.h"
#include <SDL2/SDL.h>

MainMenu::MainMenu()
	: highlighted(None)
	, background()
	, buttonStart()
	, buttonQuit()
	, selection()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::render(SDL_Renderer* renderer)
{
	// if(!background.ready) background.init(renderer, "background.png");
	if(!buttonStart.ready) buttonStart.init(renderer, "start.png");
	if(!buttonQuit.ready) buttonQuit.init(renderer, "quit.png");
	if(!selection.ready) selection.init(renderer, "select.png");

	//background.render(0,0);
	buttonStart.render(100, 100);
	buttonQuit.render(100, 400);
	if(highlighted == QuitButton)
		selection.render(50, 400);
	else
		selection.render(50, 100);
}

void MainMenu::handleEvent(SDL_Event& event)
{
	if(event.type == SDL_KEYDOWN)
	{
		highlighted == StartButton;
	}
}

void MainMenu::update()
{
	
}

bool MainMenu::shouldStart()
{
	return open;
}


