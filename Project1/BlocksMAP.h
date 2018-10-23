#pragma once

#include "Vector2D.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include "Block.h"

class BlocksMAP
{
private:
	Block*** blocks;//Matriz dinámica de punteros a bloques
	uint MapSizeX;
	uint MapSizeY;//Tamaño en píxeles del mapa
	uint BlockSize ; //Tamaño en píxeles del bloque
	uint numBlocks;

public:
	BlocksMAP(uint x, uint y, uint tamBloque);
	~BlocksMAP();
	void render();
	uint BlockNum();
	void loadFile(const string& filePath);
};

