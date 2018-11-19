#include "MovingObject.h"

MovingObject::MovingObject(Vector2D pos, int width, int height, Texture * texture, Vector2D dir):ArkanoidObject(pos, width, height, texture)
{
	dirPos = dir;
}


MovingObject::~MovingObject()
{
}

	//ArkanoidObject::saveToFile(); //+ (dir...)


Vector2D MovingObject::getDirection()
{
	return dirPos;
}

void MovingObject::loadFromFile(string filepath)
{
	ifstream file(filepath);
	ArkanoidObject::loadFromFile(file);
	double dirPosX;
	double dirPosY;

	file >> dirPosX;
	file >> dirPosY;
	position = Vector2D(dirPosX, dirPosY);
}

void MovingObject::update()
{
	position = position + dirPos;
}
