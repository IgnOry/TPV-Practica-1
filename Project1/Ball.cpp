#include "Ball.h"
#include "Game.h"

Ball::Ball(Vector2D pos, uint anch, uint alt, Vector2D direccion, Texture* puntero, Game* juego)
{
	posicion = pos;
	ancho = anch;
	alto = alt;
	dirPos = direccion;
	punteroTextura = puntero;
	punteroGame = juego;
}

Ball::~Ball()
{
}

void Ball::render()
{
}

void Ball::update()
{



}


