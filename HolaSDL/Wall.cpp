#include "Wall.h"

Wall::Wall(Vector2D pos, int width, int height, Texture * texture):ArkanoidObject(pos, width, height, texture)
{
}

Wall::~Wall()
{
}

void Wall::render()
{			
	ptrTexture->render(getRect());		// renderiza el de la izda
}


