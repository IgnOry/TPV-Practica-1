#include "Block.h"



Block::Block()
{
}


Block::~Block()
{
}

void Block::render()
{
	texture->load("..\\images\\bricks.png", 6, 1); // El 6 y el 1 son valores que habrá que cambiar probablemente

	SDL_Rect destRect = { x, y, w, h };

	texture->render(destRect, SDL_FLIP_NONE);
}
