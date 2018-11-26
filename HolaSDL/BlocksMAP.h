#pragma once

#include "Vector2D.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include "Block.h"
#include "checkML.h"
#include "ArkanoidObject.h"


class BlocksMAP: public ArkanoidObject
{
private:
	Block*** blocks;//Matriz dinámica de punteros a bloques
	uint colums;
	uint rows;
	uint BlockSize; //Tamaño en píxeles del bloque
	uint numBlocks;
	Texture* texture; //textura de los bloques, para pasarla a la hora de construirlos

public:
	BlocksMAP();
	BlocksMAP(string filepath, Texture * textureD, uint ELEM_BLOCK);
	~BlocksMAP();
	void render();
	uint BlockNum();
	void loadFromFile(ifstream & file);
	void loadBlocks(ifstream& file);
	void loadFile(const string& filePath, Texture* texture, uint ELEM_BLOCK);
	int size();
	Block * collides(const SDL_Rect & ballRect, const Vector2D & ballVel, Vector2D & collVector);
	Block * blockAt(const Vector2D & p);
	void ballHitsBlock(Block& block);
	uint MapX();
	uint MapY();
	Block *** BlockStructure();
	void saveToFile(ofstream& file);
};

