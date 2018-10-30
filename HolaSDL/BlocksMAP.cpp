#include "BlocksMAP.h"
#include <iostream>
#include <fstream>



BlocksMAP::BlocksMAP()
{
}

BlocksMAP::BlocksMAP(string filepath, Texture* textureD, uint ELEM_BLOCK)
{
	loadFile(filepath, textureD, ELEM_BLOCK);
}

BlocksMAP::~BlocksMAP()
{
}

void BlocksMAP::render()
{
	uint rows = MapSizeX;
	uint columns = MapSizeY;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			if (blocks[r][c] != nullptr)
			blocks[r][c]->render();
		}
	}
}

uint BlocksMAP::BlockNum()
{
	return numBlocks;
}

void BlocksMAP::loadFile(const string& filePath, Texture* textureD, uint ELEM_BLOCK)
{
	ifstream file;
	file.open(filePath);

	int x;
	int y;

	file >> x >> y;

	blocks = new Block**[x];
	for (int i = 0; i < y; i++)
		blocks[i] = new Block*[y];

	BlockSize = ELEM_BLOCK;
	MapSizeX = x;
	MapSizeY = y;
	texture = textureD;
	
	int colour;
	for (int r = 0; r < x; r++) {
		for (int c = 0; c < y; c++) {
			file >> colour;
			if (colour == 0)
				blocks[r][c] = nullptr;
			else
			{
				blocks[r][c] = new Block(BlockSize,(BlockSize/3), BlockSize, BlockSize/3, colour, c, r, textureD);
				numBlocks++;
			}
		}
	}
}
int BlocksMAP::size() {
	return MapSizeY * (BlockSize/3);
}

Block* BlocksMAP::collides(const SDL_Rect& rect) {
	Block * block = new Block;
	return block;
}
