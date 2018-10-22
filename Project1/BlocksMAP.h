#pragma once

#include "Vector2D.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"

class BlocksMAP
{
private:
	//Matriz din�mica de punteros a bloques
	uint tamMapap; //Tama�o en p�xeles del mapa
	uint tamBloque; //Tama�o en p�xeles del bloque

public:
	BlocksMAP();
	~BlocksMAP();
	void render();
	int numBloques();
	void cargarArchivo();
};

