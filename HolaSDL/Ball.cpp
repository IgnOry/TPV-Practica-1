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
	SDL_Rect srcRect = {position.getX(), position.getY(), width, height};
	ptrTexture->render(srcRect);
}

void Ball::update()
{
	Vector2D prevPos = position;
	position = position + dirPos;
	Vector2D collVector;
	/*SDL_Rect ballRect = getDestRect();

	if (ptrGame.collides(ballRect, vel, collVector))
	{
		dirPos = dirPos - collVector * (2 * dirPos*collVector);
		pos = prevPos + dirPos;
	}*/

}


