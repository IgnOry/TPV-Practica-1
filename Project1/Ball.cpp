#include "Ball.h"
#include "Game.h"

Ball::Ball(Vector2D pos, uint widthN, uint heightN, Vector2D direction, Texture* ptrTextureD, Game* ptrGameD)
{
	position = pos;
	width = widthN;
	height = heightN;
	dirPos = direction;
	ptrTexture = ptrTextureD;
	ptrGame = ptrGameD;
}

Ball::~Ball()
{
}

void Ball::render()
{
}

void Ball::update()
{



}


