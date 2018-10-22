#include "Paddle.h"

Paddle::Paddle(Vector2D pos, uint wid, uint heightD, Vector2D direction, Texture* ptr)
{
	position = pos;
	width = wid;
	height = heightD;
	dirPos = direction;
	ptrTexture = ptr;
}

Paddle::~Paddle()
{
}

void Paddle::render()
{
	SDL_Rect srcRect = { position.getX, position.getY, width, height };
	ptrTexture->render(srcRect);
}

void Paddle::update()
{
}

void Paddle::handleEvents()
{
}
