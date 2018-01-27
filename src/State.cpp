#include "State.h"

#include <SDL2/SDL.h>

#include "MainMenu.h"
#include "ScoreScreen.h"
#include "PauseMenu.h"
#include "Level.h"

State::State()
{
	mainMenu = new MainMenu;
	pauseMenu = new PauseMenu;
	scoreScreen = new ScoreScreen;
	level = new Level; //::createLevel(0);
}

State::~State()
{
	delete mainMenu;
	delete pauseMenu;
	delete scoreScreen;
	delete level;
}

void State::update(float deltaTime)
{
	if(inMainMenu)
	{
		mainMenu->update();
		inMainMenu = mainMenu->isOpen();
		if(!inMainMenu)
		{
			if(mainMenu->shouldStart())
			{
				inPauseMenu = false;
				inScoreScreen = false;
				inLevel = true;
				startGame();
			}
			else
			{
				inPauseMenu = false;
				inScoreScreen = false;
				inLevel = false;
			}
		}
	}

	else if(inPauseMenu)
	{
		pauseMenu->update();
		inPauseMenu = pauseMenu->isOpen();
		if(!inPauseMenu)
		{
			if(pauseMenu->shouldExit())
			{
				inMainMenu = true;
				inScoreScreen = false;
				inLevel = false;
				mainMenu->show();
			}
			else
			{
				inMainMenu = false;
				inScoreScreen = false;
				inLevel = true;
			}
		}
	}

	else if(inScoreScreen)
	{
		scoreScreen->update();
		inScoreScreen = scoreScreen->isOpen();
		if(inScoreScreen)
		{
			inMainMenu = true;
			mainMenu->show();
		}
	}

	else if(inLevel)
	{
		level->update(deltaTime);
		score += level->getScoreIncrease();
		if(level->menuOpened())
		{
			inPauseMenu = true;
			pauseMenu->show(score);
		}
		if(level->finished())
			nextLevel();
		if(level->isGameOver())
		{
			inLevel = false;
			inScoreScreen = true;
			scoreScreen->show(score);
		}
	}
}

void State::render(SDL_Renderer* renderer)
{
	if (inMainMenu)
		mainMenu->render(renderer);
	else if (inPauseMenu)
		pauseMenu->render(renderer);
	else if (inScoreScreen)
		scoreScreen->render(renderer);
	else if (inLevel)
		level->render(renderer);
}

bool State::gameOver()
{
	return (!inMainMenu || !inPauseMenu || !inScoreScreen || !inLevel);
}

void State::startGame()
{
	score = 0;
	levelNumber = 0;
	// level = createLevel(levelNumber);
}

void State::nextLevel()
{
	levelNumber++;
	delete level;
	level = new Level();//::createLevel(levelNumber);
}
