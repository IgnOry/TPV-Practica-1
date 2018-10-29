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

void Block::render()
{	
	int row = 0;
	if (colour > 2)
	{
		row = 1;
		colour = colour - 3;
	}

	SDL_Rect destRect = {position.getX()*rows+20, position.getY()*columns+20,width, height};

	ptrTexture->renderFrame(destRect,row,colour);
		
}
