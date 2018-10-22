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
		uint ancho;
		uint alto;
		Vector2D dirPos;
		Texture* punteroTextura;
		Game* punteroGame;
public:
	Ball(Vector2D pos, uint anch, uint alt, Vector2D direccion, Texture* puntero, Game* juego);
	~Ball();
	void render();
	void update();
};

