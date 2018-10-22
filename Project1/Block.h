#pragma once

#include "Vector2D.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"

#include <string>


class Block
{

private:
	Vector2D posicion;
	uint ancho;
	uint alto;
	uint color;
	uint fila;
	uint columna;
	Texture* punteroTextura;

public:
	Block(double posX, double posY, int numAncho, int tamAlto, int tamColor, int tamFila, int tamColumna, Texture* textura);
	~Block();
	void render();
};

