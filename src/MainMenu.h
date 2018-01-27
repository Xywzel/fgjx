#pragma once

#include "Menu.h"

class MainMenu : public Menu
{
	public:
		virtual void render();
		virtual void update();
		virtual bool isOpen();
		virtual void show(int arg = 0);
		bool shouldStart();
	private:
		bool open;
};


