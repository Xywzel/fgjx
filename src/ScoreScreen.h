#pragma once

#include "Menu.h"

class ScoreScreen : public Menu
{
	public:
		ScoreScreen();
		virtual ~ScoreScreen();
		virtual void render(SDL_Renderer* renderer);
		virtual void update();
		virtual void show(int arg = 0);
	private:
		int score;
};
