#pragma once

class Object
{
	enum class Type: int
	{
		Door
	};

	Type objectType;
	float objectX, objectY;
	public:
		Object(Type type, float x, float y);
		~Object();
		float getX();
		float getY();
		Type getType();
};
