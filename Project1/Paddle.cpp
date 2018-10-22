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
}

void Paddle::update()
{
}

void Paddle::handleEvents()
{
}
