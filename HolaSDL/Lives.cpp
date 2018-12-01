#include "Lives.h"



Lives::Lives(Vector2D pos, int width, int height, Texture * texture) :ArkanoidObject(pos, width, height, texture)
{
	lives = 3;
}


Lives::~Lives()
{
}

uint Lives::getLives()
{
	return lives;
}

void Lives::less()
{
	lives--;
}

void Lives::render()
{
	for (int i = 0; i - lives; i++) {
		SDL_Rect rect = getRect();
		rect.x -= rect.w * i;
		ptrTexture->render(rect);
	}
}
