#include "Block.h"

Block::Block(double posX, double posY, int widthN, int heightN, int colourN, int rowN, int columnN, Texture * texture)
{
	position = Vector2D::Vector2D(posX, posY);
	width = widthN;
	height = heightN;
	colour = colourN;
	rows = rowN;
	columns = columnN;
	ptrTexture = texture;
}

Block::~Block()
{
}

void Block::render()
{	
	int row = 0;
	if (colour > 3)
	{
		colour = colour - 3; //para la columna de las texturas
		row = 1;
	}

	SDL_Rect destRect = {position.getX(), position.getY(),width, height};

	//SDL_Rect R = {position.getX(),position.getY(),width, height };
	
	ptrTexture->renderFrame(destRect, row, colour);
		
}
