#pragma once
#include "LTexture.h"

struct SDL_Renderer;

class Object
{
	enum class Type: int
	{
		Door
	};

	Type objectType;
	float objectX, objectY;
	LTexture sprite;
	public:
		Object(Type type, float x, float y);
		~Object();
		float getX();
		float getY();
		Type getType();
		void render(SDL_Renderer* renderer);
		void update(float deltaTime);
};
