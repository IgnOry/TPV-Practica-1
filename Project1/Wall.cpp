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
	SDL_Rect destRect = { position.getX(), position.getY(), 0, 0};			
	ptrTexture->render(destRect);		// renderiza el de la izda
	ptrTexture->render(destRect,SDL_FLIP_HORIZONTAL);		// renderiza el de arriba

	SDL_Rect destRect = { position.getX(), position.getY(), 0, height };
	ptrTexture->render(destRect);	// renderiza el de la abajo

	SDL_Rect destRect = {position.getX(), position.getY(), width, 0};	
	ptrTexture->render(destRect);	// renderiza el de la dcha
}
