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

void Block::render()		//hay que elegir qué textura se renderiza

{}
/*{
	SDL_Rect destRect = { position.getX, position.getY,width, height};

	for (int r = 0; r < rows; r++) 
	{
		for( int c = 0; c < columns; c++){
			if (columns[r][c] != nullptr) {
				SDL_Rect R = { (position.getX() + r), (position.getY() + c),width, height };
				ptrTexture->render(destRect);
			}

		}

	}
}
	ptrTexture->load("..\\images\\bricks.png", 6, 1);

	SDL_Rect destRect = { x, y, w, h };

	ptrTexture->render(destRect);
}*/
