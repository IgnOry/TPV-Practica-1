#include "Block.h"

Block::Block(double posX, double posY, int widthN, int heightN, int colourN, int rowN, int columnN, Texture * texture)
{
	position = Vector2D::Vector2D(posX,posY);
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
	ptrTexture->load("..\\images\\bricks.png", 6, 1);

	SDL_Rect destRect = { x, y, w, h };

	ptrTexture->render(destRect, SDL_FLIP_NONE);
}
