#include "BlocksMAP.h"
#include "Game.h"
#include <iostream>
#include <fstream>



BlocksMAP::BlocksMAP(uint x, uint y, uint tamBloqueDato, Texture* textureD)
{
	blocks = new Block**[x];
	for (int i = 0; i < y; i++)
		blocks[i] = new Block*[y];
	
	BlockSize = tamBloqueDato;
	MapSizeX = tamBloqueDato * x;
	MapSizeY = tamBloqueDato * y;
	texture = textureD;
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

	int x;
	int y;

	file >> x >> y;

	BlocksMAP::BlocksMAP(x, y, BlockSize, texture);
	
	for (uint r = 0; r < x; r++) {
		for (uint c = 0; c < y; c++) {

		}
	}
	int colour;
	for (int r = 0; r < x; r++) {
		for (int c = 0; c < y; c++) {
			file >> colour;
			if (colour == 0)
				blocks[x][y] = nullptr;
			else
				blocks[x][y] = new Block(r * BlockSize, c * (BlockSize / 7), BlockSize, BlockSize / 7, colour, r, c, texture);
			numBlocks++;
		}
	}
}
