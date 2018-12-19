#include "Block.h"


Block::Block(Vector2D pos, int widthN, int heightN, int colourN, int rowN, int columnN, Texture * texture):ArkanoidObject(pos,widthN,heightN,texture)
{
	colour = colourN;
	columns = columnN;
	rows = rowN;
	
}

void Block::render() 
{
	texture->renderFrame(getRect(), colour / texture->getNumCols(), colour%texture->getNumCols());
}

Block::~Block()
{
}

uint Block::row()
{
	return rows;
}

uint Block::colum() 
{
	return columns;
}

bool Block::handleEvent(SDL_Event e)
{
	return false;
}

uint Block::getY()
{
	return uint(position.getY());
}

uint Block::getX()
{
	return uint(position.getX());
}

uint Block::getH()
{
	return height;
}

uint Block::getW()
{
	return width;
}

int Block::getColour()
{
	return colour;
}
