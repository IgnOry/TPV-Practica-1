#pragma once

#include "Vector2D.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include "Block.h"

class BlocksMAP
{
private:
	Block*** bloques;//Matriz dinámica de punteros a bloques
	uint tamMapaX;
	uint tamMapaY;//Tamaño en píxeles del mapa
	uint tamBloque; //Tamaño en píxeles del bloque

public:
	BlocksMAP(uint x, uint y, uint tamBloque);
	~BlocksMAP();
	void render();
	uint numBloques();
	void cargarArchivo(string filePath);
};

