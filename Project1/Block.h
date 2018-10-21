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
	SDL_Texture* punteroTextura;

public:
	Block();
	~Block();
	void render();
};

