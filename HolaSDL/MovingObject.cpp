#include "MovingObject.h"

MovingObject::MovingObject(Vector2D pos, int width, int height, Texture * texture, Vector2D dir):ArkanoidObject(pos, width, height, texture)
{
	dirPos = dir;
}


MovingObject::~MovingObject()
{
}

Vector2D MovingObject::getDirection()
{
	return dirPos;
}

void MovingObject::loadFromFile(ifstream& file)
{
	ArkanoidObject::loadFromFile(file);
	double dirPosX;
	double dirPosY;

	file >> dirPosX;
	file >> dirPosY;
	position = Vector2D(dirPosX, dirPosY);
}

void MovingObject::saveToFile(ofstream& file)
{
	ArkanoidObject::saveToFile(file);
	file << dirPos.getX() << endl;
	file << dirPos.getY() << endl;

	//Actualizar en MovingObject y dem�s el m�todo para guardar m�s datos

}

void MovingObject::update()
{
	position = position + dirPos;
}

void MovingObject::reset(Vector2D pos, Vector2D dir) {
	position = pos;
	dirPos = dir;
}
