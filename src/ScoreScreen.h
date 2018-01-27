#pragma once

#include "Menu.h"

class ScoreScreen : public Menu
{
	public:
		virtual void render();
		virtual void update();
		virtual bool isOpen();
		virtual void show(int arg = 0);
	private:
		bool open;
		int score;
};
