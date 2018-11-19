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

void ArkanoidObject::loadFromFile(ifstream file) // dependiendo del objeto, será llamado desde movingobject o "a pelo"
{
	double PosX;
	double PosY;

	file >> PosX;
	file >> PosY;
	position = Vector2D(PosX, PosY);
}

void ArkanoidObject::saveToFile() //ver si se puede pasar el nombre de archivo como constante, incluyendo Game.h en la clase, o se pone a mano
{
	ofstream saveFile("..\\saves\\save.ark");
	saveFile << position.getX() << endl;
	saveFile << position.getY() << endl;

	//Actualizar en MovingObject y demás el método para guardar más datos

	saveFile.close();
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
