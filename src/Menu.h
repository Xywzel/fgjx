#pragma once

struct SDL_Renderer;

class Menu
{
	public:
		Menu();
		virtual ~Menu();
		virtual void render(SDL_Renderer* renderer) = 0;
		virtual void update() = 0;
		bool isOpen();
		virtual void show(int arg = 0);
	private:
		bool open;
};
