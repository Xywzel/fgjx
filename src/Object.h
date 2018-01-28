#pragma once
#include "LTexture.h"

struct SDL_Renderer;

class Object
{
	public:
	enum class Type: int
	{
		Door
	};

		Object(Type type, float x, float y);
		~Object();
		float getX();
		float getY();
		Type getType();
		void render(SDL_Renderer* renderer);
		void update(float deltaTime);
	private:
		Type type;
		float x, y;
		LTexture sprite;
};
