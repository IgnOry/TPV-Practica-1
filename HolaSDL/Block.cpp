#include "Block.h"

Block::Block(double posX, double posY, int widthN, int heightN, int colourN, int rowN, int columnN, Texture * texture)
{
	position = Vector2D::Vector2D(posX, posY);
	width = widthN;
	height = heightN;
	colour = colourN;
	columns = columnN;
	rows = rowN;
	ptrTexture = texture;
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

void Block::render()
{	
	SDL_Rect destRect = {position.getX()*rows+20, position.getY()*columns+20,width, height};

	ptrTexture->renderFrame(destRect,colour/ptrTexture->getNumCols(),colour%ptrTexture->getNumCols());
		
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
