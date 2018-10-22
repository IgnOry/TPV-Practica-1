#include "Block.h"


Block::Block(double posX, double posY, int tamAncho, int tamAlto, int tamColor, int tamFila, int tamColumna, Texture * textura)
{
	posicion = Vector2D::Vector2D(posX, posY);
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
	texture->load("..\\images\\bricks.png", 6, 1); // El 6 y el 1 son valores que habrá que cambiar probablemente

	SDL_Rect destRect = { x, y, w, h };

	texture->render(destRect, SDL_FLIP_NONE);
}
