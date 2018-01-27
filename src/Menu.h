#pragma once

struct SDL_Renderer;
union SDL_Event;

class Menu
{
	public:
		Menu();
		virtual ~Menu();
		virtual void render(SDL_Renderer* renderer) = 0;
		virtual void handleEvent(SDL_Event& e);
		virtual void update() = 0;
		bool isOpen();
		virtual void show(int arg = 0);
	protected:
		bool open;
};
