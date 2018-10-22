#include "Block.h"


Block::Block(double posX, double posY, int tamAncho, int tamAlto, int tamColor, int tamFila, int tamColumna, Texture * textura)
{
	posicion.darValor(posX, posY);
	ancho = tamAncho;
	alto = tamAlto;
	punteroTextura = textura;
	fila = tamFila;
	color = tamColor;
	columna = tamColumna;
}

Block::~Block()
{
}

void Block::render()
{
	texture->load("..\\images\\bricks.png", 6, 1);

	SDL_Rect destRect = { x, y, w, h };

	texture->render(destRect, SDL_FLIP_NONE);
}
