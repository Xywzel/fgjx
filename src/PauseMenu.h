#pragma once

#include "Menu.h"

class PauseMenu : public Menu
{
	public:
		virtual void render();
		virtual void update();
		virtual bool isOpen();
		virtual void show(int arg = 0);
		bool shouldExit();
	private:
		bool open;
};

