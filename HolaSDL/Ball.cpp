#include "Ball.h"
#include "Game.h"
#include "Texture.h"


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
	SDL_Rect srcRect = {position.getX(), position.getY(), width, height};
	ptrTexture->render(srcRect);
}

void Ball::update()
{
	Vector2D collVector = dirPos; // Vector2D(-position.getY(), position.getX());

	SDL_Rect ballRect = {position.getX(), position.getY(), width, height };

	if (ptrGame->collides(ballRect, dirPos, collVector))
	{
		collVector.normalize();

		dirPos = dirPos - (collVector *(dirPos * collVector) *2);
	}
	position = position + dirPos;

}

Vector2D Ball::getPosition()
{
	return position;
}

Vector2D Ball::getDirection()
{
	return dirPos;
}


