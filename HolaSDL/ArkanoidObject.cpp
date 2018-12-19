#include "ArkanoidObject.h"

ArkanoidObject::ArkanoidObject(): SDLGameObject()
{}

ArkanoidObject::ArkanoidObject(Vector2D pos, int w, int h, Texture* tx): SDLGameObject(pos, w,h,tx)
{
}


ArkanoidObject::~ArkanoidObject()
{
}

void ArkanoidObject::loadFromFile(ifstream& file) // dependiendo del objeto, será llamado desde movingobject o "a pelo"
{
	double PosX;
	double PosY;

	file >> PosX;
	file >> PosY;
	position = Vector2D(PosX, PosY);
}

void ArkanoidObject::saveToFile(ofstream& file)
{
	file << position.getX() << endl;
	file << position.getY() << endl;
}

Vector2D ArkanoidObject::getPosition()
{
	return position;
}
