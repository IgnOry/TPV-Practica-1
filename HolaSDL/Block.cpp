#include "Block.h"


Block::Block(Vector2D pos, int widthN, int heightN, int colourN, int rowN, int columnN, Texture * texture):ArkanoidObject(pos,widthN,heightN,texture)
{
	colour = colourN;
	columns = columnN;
	rows = rowN;
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
