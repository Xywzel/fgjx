#pragma once

#include "Menu.h"

#include "LTexture.h"

class ScoreScreen : public Menu
{
	public:
		ScoreScreen();
		virtual ~ScoreScreen();
		virtual void render(SDL_Renderer* renderer);
		virtual void handleEvent(SDL_Event& e);
		virtual void update();
		virtual void show(int arg = 0);
	private:
		int score;
		LTexture background;
		LTexture victory;
		LTexture loose;
};
