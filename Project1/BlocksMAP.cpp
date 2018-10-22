#include "BlocksMAP.h"
#include <iostream>
#include <fstream>



BlocksMAP::BlocksMAP(uint x, uint y, uint tamBloqueDato)
{
	bloques = new Block**[x];
	for (int i = 0; i < y; i++)
		bloques[i] = new Block*[y];
	
	tamBloque = tamBloqueDato;
	tamMapaX = tamBloqueDato * x;
	tamMapaY = tamBloqueDato * y;
}

BlocksMAP::~BlocksMAP()
{
}

void BlocksMAP::render()
{

}

uint BlocksMAP::numBloques()
{
	uint x = tamMapaX / tamBloque;
	uint y = tamMapaY / tamBloque;
	uint i = 0;

	for (int j = 0; j < x; j++)
	{
		for (int k = 0; k < y; k++)
		{
			if (bloques[x][y] != nullptr)
				i++;
		}
	}

	return i;
}

void BlocksMAP::cargarArchivo(string filePath)
{
	ifstream archivo;
	archivo.open(filePath);

	uint x;
	uint y;

	archivo >> x >> y;

	BlocksMAP::BlocksMAP(x, y, tamElem);
	//leer linea a linea


	//if 0 -. nullptr
	//else se crea bloque

	//asignar color por numero
}
