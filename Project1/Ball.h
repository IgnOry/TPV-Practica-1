#pragma once

#include "Vector2D.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include "Game.h"

#include <string>

class Ball
{

private:
		Vector2D posicion;
		int ancho;
		int alto;
		Vector2D dirPos;
		SDL_Texture* punteroTextura;
		Game* punteroGame;
public:
	Ball();
	~Ball();
};

