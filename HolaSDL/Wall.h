#pragma once

#include "Vector2D.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include "checkML.h"

class Wall
{

private:
	Vector2D position;
	uint width;
	uint height;
	Texture* ptrTexture;

public:
	Wall(double posX, double posY, int width, int height, Texture* texture);
	~Wall();
	void render();
	SDL_Rect rect();
};

