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

void ArkanoidObject::loadFromFile() //ver si se puede pasar el nombre de archivo como constante, incluyendo Game.h en la clase, o se pone a mano
{
	ifstream FileData("..\\saves\\save.ark");

	double PosX;
	double PosY;

	FileData >> PosX;
	FileData >> PosY;
	position = Vector2D(PosX, PosY);

	//Actualizar en MovingObject y demás el método para cargar más datos

	FileData.close();
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
