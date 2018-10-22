#include "Wall.h"



Wall::Wall(double posX, double posY, int tamAncho, int tamAlto, Texture* textura)
{
	posicion.darValor(posX, posY);
	ancho = tamAncho;
	alto = tamAlto;
	punteroTextura = textura;
}


Wall::~Wall()
{
}

void Wall::render()
{
	punteroTextura->load("..\\images\\dog.png", 6, 1); //cambiar ruta

	SDL_Rect destRect = {posicion.consultaX, posicion.consultaY,ancho, alto};

	punteroTextura->render(destRect, SDL_FLIP_NONE);

}
