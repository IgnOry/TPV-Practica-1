#include "ArkanoidObject.h"


ArkanoidObject::ArkanoidObject()
{
}

ArkanoidObject::ArkanoidObject(Vector2D pos, int w, int h, Texture* tx)
{
	position = pos;
	width = w;
	height = h;
	ptrTexture = tx;
}


ArkanoidObject::~ArkanoidObject()
{
	ptrTexture = nullptr;
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

SDL_Rect ArkanoidObject::getRect()
{
	SDL_Rect rect = { position.getX(), position.getY(), width, height };
	return rect;
}

Vector2D ArkanoidObject::getPosition()
{
	return position;
}

void ArkanoidObject::render()
{
	ptrTexture->render(getRect());
}
