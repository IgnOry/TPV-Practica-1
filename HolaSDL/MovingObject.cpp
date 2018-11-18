#include "MovingObject.h"



MovingObject::MovingObject()
{
}


MovingObject::~MovingObject()
{
}

void MovingObject::updateClass()
{
	ArkanoidObject::loadFromFile(); //+ (dir = Vector2D(0,0));

	ArkanoidObject::saveToFile(); //+ (dir...)
}

Vector2D MovingObject::getDirection()
{
	return dirPos;
}
