#pragma once

#include "Vector2D.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"

#include <string>


class Block
{

private:
	Vector2D position;
	uint width;
	uint height;
	uint colour;
	uint rows;
	uint columns;
	Texture* ptrTexture;

public:
	Block(double posX, double posY, int widthN, int heightN, int colourN, int columnN, int rowN, Texture* texture);
	~Block();
	void render();
};

