#include "Object.h"

Object::Object(Object::Type type, float x, float y)
: type(type)
, x(x)
, y(y)
{
}

Object::~Object()
{
}

float Object::getX()
{
	return x;
}

float Object::getY()
{
	return y;
}

Object::Type Object::getType()
{
	return type;
}

void Object::render(SDL_Renderer* renderer)
{
	if(!sprite.ready)
	{
		sprite.init(renderer, "door_front.png");
	}
	sprite.render(x, y, 0.1f);
}

void Object::update(float /*deltaTime*/)
{
	
}
