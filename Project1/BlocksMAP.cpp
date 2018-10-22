#include "BlocksMAP.h"
#include <iostream>
#include <fstream>



BlocksMAP::BlocksMAP(uint x, uint y, uint tamBloqueDato)
{
	blocks = new Block**[x];
	for (int i = 0; i < y; i++)
		blocks[i] = new Block*[y];
	
	BlockSize = tamBloqueDato;
	MapSizeX = tamBloqueDato * x;
	MapSizeY = tamBloqueDato * y;
}

BlocksMAP::~BlocksMAP()
{
}

void BlocksMAP::render()
{

}

uint BlocksMAP::BlockNum()
{
	uint x = MapSizeX / BlockSize;
	uint y = MapSizeY / BlockSize;
	uint i = 0;

	for (int j = 0; j < x; j++)
	{
		for (int k = 0; k < y; k++)
		{
			if (blocks[x][y] != nullptr)
				i++;
		}
	}

	return i;
}

void BlocksMAP::loadFile(string filePath)
{
	ifstream file;
	file.open(filePath);

	uint x;
	uint y;

	file >> x >> y;

	BlocksMAP::BlocksMAP(x, y, BlockSize);
	//leer linea a linea


	//if 0 -. nullptr
	//else se crea bloque

	//asignar color por numero
}
