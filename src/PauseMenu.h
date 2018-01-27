#pragma once

#include "Menu.h"

class PauseMenu : public Menu
{
	public:
		PauseMenu();
		virtual ~PauseMenu();
		virtual void render();
		virtual void update();
		virtual bool isOpen();
		virtual void show(int arg = 0);
		bool shouldExit();
	private:
		bool open;
};

