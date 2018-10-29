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
	uint MapSizeY;
	uint BlockSize; //Tama�o en p�xeles del bloque
	uint numBlocks;
	Texture* texture; //textura de los bloques, para pasarla a la hora de construirlos

public:
	BlocksMAP();
	BlocksMAP(string filepath, Texture * textureD, uint ELEM_BLOCK);
	~BlocksMAP();
	void render();
	uint BlockNum();
	void loadFile(const string& filePath, Texture* texture, uint ELEM_BLOCK);
};

