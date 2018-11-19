#include "Ball.h"
#include "Game.h"
#include "Texture.h"


Ball::Ball(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction, Game* ptrGameD):MovingObject(pos, wid, heightD, ptr, direction)
{
	ptrGame = ptrGameD;
}

Ball::~Ball()
{
}

void Ball::update()
{
	Vector2D collVector = dirPos; // Vector2D(-position.getY(), position.getX());

	SDL_Rect ballRect = getRect();

	if (ptrGame->collides(ballRect, dirPos, collVector))
	{
		collVector.normalize();

		dirPos = dirPos - (collVector *(dirPos * collVector) *2);
	}
	MovingObject::update();
}


