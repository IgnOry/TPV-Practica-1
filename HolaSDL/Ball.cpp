#include "Ball.h"
#include "PlayState.h"
#include "Texture.h"


Ball::Ball(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction, PlayState* st):MovingObject(pos, wid, heightD, ptr, direction){
	state = st;
}

Ball::~Ball()
{
}

void Ball::update()
{
	Vector2D collVector = dirPos; // Vector2D(-position.getY(), position.getX());

	SDL_Rect ballRect = getRect();

	if (state->collides(ballRect, dirPos, collVector))
	{
		collVector.normalize();

		dirPos = dirPos - (collVector *(dirPos * collVector) *2);
	}
	MovingObject::update();
}


