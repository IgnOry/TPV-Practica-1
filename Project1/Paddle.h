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
	int ancho;
	int alto;
	Vector2D dirPos;
	SDL_Texture* punteroTextura;

public:
	Paddle();
	~Paddle();
	void render();
	void update();
	void handleEvents();
};

