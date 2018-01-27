#pragma once
#include "LTexture.h"

struct SDL_Renderer;

class Player
{
	float playerX, playerY;
	LTexture avatar;
	public:
		float getX();
		float getY();
		void render(SDL_Renderer* renderer);
};
