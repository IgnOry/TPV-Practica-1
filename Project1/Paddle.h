#pragma once

#include "Vector2D.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"

#include <string>

class Paddle
{

private:
	Vector2D posicion;
	uint ancho;
	uint alto;
	Vector2D dirPos;
	Texture* punteroTextura;

public:
	Paddle(Vector2D pos, uint anch, uint alt, Vector2D direccion, Texture* puntero);
	~Paddle();
	void render();
	void update();
	void handleEvents();
};

