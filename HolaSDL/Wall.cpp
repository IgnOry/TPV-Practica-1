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

SDL_Rect Wall::rect() {
	SDL_Rect rect = { position.getX(), position.getY(), width, height };
	return rect;
}

void Wall::render()
{			
	ptrTexture->render(rect());		// renderiza el de la izda
}


