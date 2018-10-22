#pragma once

#include "Vector2D.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include "Block.h"

class BlocksMAP
{
private:
	Block*** bloques;//Matriz din�mica de punteros a bloques
	uint tamMapaX;
	uint tamMapaY;//Tama�o en p�xeles del mapa
	uint tamBloque; //Tama�o en p�xeles del bloque

public:
	BlocksMAP(uint x, uint y, uint tamBloque);
	~BlocksMAP();
	void render();
	uint numBloques();
	void cargarArchivo(string filePath);
};

