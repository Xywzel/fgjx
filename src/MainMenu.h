#pragma once

#include "Menu.h"

#include "LTexture.h"

class MainMenu : public Menu
{
	public:
		MainMenu();
		virtual ~MainMenu();
		virtual void handleEvent(SDL_Event& e);
		virtual void render(SDL_Renderer* renderer);
		virtual void update();
		bool shouldStart();
	private:
		enum Button {
			StartButton,
			QuitButton,
			None,
		};
		Button highlighted;
		LTexture background;
		LTexture buttonStart;
		LTexture buttonQuit;
		LTexture selection;
		LTexture intro;
		bool start;
};


