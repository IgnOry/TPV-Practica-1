#include "Wall.h"



Wall::Wall(double posX, double posY, int tamAncho, int tamAlto, Texture* textura)
{
	posicion = Vector2D::Vector2D(posX, posY);
	ancho = tamAncho;
	alto = tamAlto;
	punteroTextura = textura;
}


Wall::~Wall()
{
}

void Wall::render()
{
}
