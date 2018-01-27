#include "Object.h"

Object::Object(Object::Type type, float x, float y)
: objectType(type)
, objectX(x)
, objectY(y)
{
	
}

Object::~Object()
{

}

float Object::getX()
{
	return objectX;
}

float Object::getY()
{
	return objectY;
}

Object::Type Object::getType()
{
	return objectType;
}
