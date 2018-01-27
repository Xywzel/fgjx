#pragma once
#include "LTexture.h"

struct SDL_Renderer;
union SDL_Event;

class Player
{
	public:
		Player();
		~Player();
		void update(float deltaTime);
		void render(SDL_Renderer* renderer);
		void handleEvent(SDL_Event& e);
		float getX();
		float getY();
		void setXY(float x, float y);
	private:
		float x, y;
		float xSpeed, ySpeed;
		LTexture avatar;
};
