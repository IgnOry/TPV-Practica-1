#include "Wall.h"



Wall::Wall(double posX, double posY, int tamAncho, int tamAlto, Texture* textura)
{
	position = Vector2D::Vector2D(posX, posY);
	width = tamAncho;
	height = tamAlto;
	ptrTexture = textura;
}


Wall::~Wall()
{
}

void Wall::render()
{
	ptrTexture->load("..\\images\\dog.png", 6, 1); //cambiar ruta

	SDL_Rect destRect = {position.getX(), position.getY(), width, height};

	ptrTexture->render(destRect, SDL_FLIP_NONE);

}
