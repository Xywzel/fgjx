#pragma once

class Menu
{
	public:
		virtual void render();
		virtual void update();
		virtual bool isOpen();
		virtual void show(int arg = 0);
	private:
		bool open;
};
