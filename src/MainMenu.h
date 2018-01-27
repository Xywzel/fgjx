#pragma once

#include "Menu.h"

class MainMenu : public Menu
{
	public:
		MainMenu();
		virtual ~MainMenu();
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
};


