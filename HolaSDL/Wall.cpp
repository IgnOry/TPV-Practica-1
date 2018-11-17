#include "Wall.h"

Wall::Wall(Vector2D pos, int width, int height, Texture * texture)
{
}

Wall::~Wall()
{
}

SDL_Rect Wall::rect() {
	SDL_Rect rect = { position.getX(), position.getY(), width, height };
	return rect;
}

void Wall::render()
{			
	ptrTexture->render(rect());		// renderiza el de la izda
}


