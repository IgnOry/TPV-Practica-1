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
	//uint rows = MapSizeX / BlockSize;
	//uint columns = MapSizeY / BlockSize;
	//for (int r = 0; r < rows; r++)
}

uint BlocksMAP::BlockNum()
{
	return numBlocks;
}

void BlocksMAP::loadFile(const string& filePath)
{
	ifstream file;
	file.open(filePath);

	uint x;
	uint y;

	file >> x >> y;

	BlocksMAP::BlocksMAP(x, y, BlockSize);
	//leer linea a linea
	
	//file >> color;
	//if (color == 0)
	//	cells[x][y] = nullptr;
	//else
	//	{cell[x][y] = new Block(...)
	//   numblocks++}

	//if 0 -. nullptr
	//else se crea bloque

	//asignar color por numero
}
