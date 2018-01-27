#pragma once

#include "Menu.h"

#include "LTexture.h"

class PauseMenu : public Menu
{
	public:
		PauseMenu();
		virtual ~PauseMenu();
		virtual void render(SDL_Renderer* renderer);
		virtual void handleEvent(SDL_Event& e);
		virtual void update();
		virtual void show(int arg = 0);
		bool shouldExit();
	private:
		int score;
		
		enum Button{
			MenuButton,
			ContinueButton,
		};
		Button current;

		LTexture background;
		LTexture menuButton;
		LTexture continueButton;
		LTexture selection;
};

