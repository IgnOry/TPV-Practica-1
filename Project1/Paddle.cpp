#include "Paddle.h"

Paddle::Paddle(Vector2D pos, uint anch, uint alt, Vector2D direccion, Texture* puntero)
{
	posicion = pos;
	ancho = anch;
	alto = alt;
	dirPos = direccion;
	punteroTextura = puntero;
}

Paddle::~Paddle()
{
}

void Paddle::render()
{
}

void Paddle::update()
{
}

void Paddle::handleEvents()
{
}
