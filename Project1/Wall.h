#pragma once

#include "Vector2D.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"

class Wall
{

private:
	Vector2D posicion;
	uint ancho;
	uint alto;
	Texture* punteroTextura;

public:
	Wall(double posX, double posY, int ancho, int alto, Texture* textura);
	~Wall();
	void render();
};

