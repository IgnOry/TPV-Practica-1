#pragma once

#include "Vector2D.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"

class BlocksMAP
{
private:
	//Matriz dinámica de punteros a bloques
	uint tamMapap; //Tamaño en píxeles del mapa
	uint tamBloque; //Tamaño en píxeles del bloque

public:
	BlocksMAP();
	~BlocksMAP();
	void render();
	int numBloques();
	void cargarArchivo();
};

