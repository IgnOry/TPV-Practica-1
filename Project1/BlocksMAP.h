#pragma once

#include "Vector2D.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include "Block.h"

class BlocksMAP
{
private:
	Block*** blocks;//Matriz din�mica de punteros a bloques
	uint MapSizeX;
	uint MapSizeY;//Tama�o en p�xeles del mapa
	uint BlockSize ; //Tama�o en p�xeles del bloque
	uint numBlocks;

public:
	BlocksMAP(uint x, uint y, uint tamBloque);
	~BlocksMAP();
	void render();
	uint BlockNum();
	void loadFile(const string& filePath);
};

