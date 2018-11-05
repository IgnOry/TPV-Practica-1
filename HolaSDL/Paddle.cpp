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
	SDL_Rect srcRect = {position.getX(), position.getY(), width, height };
	ptrTexture->render(srcRect);
}

void Paddle::update()
{
	if (position.getX() >= 20 && position.getX() <= 660)
		position = position + dirPos;

	else
	{
		if (position.getX() < 20)
		{
			position = position + Vector2D(1, 0);
			dirPos = Vector2D(0, 0);
		}
		else if (position.getX() > 660)
		{
			position = position + Vector2D(-1, 0);
			dirPos = Vector2D(0, 0);
		}
	}
}



void  Paddle::handleEvents(SDL_Event event)
{
	if(event.type == SDL_KEYUP)
		dirPos = Vector2D(0, 0);
	else {
		switch (event.key.keysym.sym)
		{
		case(SDLK_RIGHT):
			dirPos = Vector2D(0.2, 0);
			break;

		case (SDLK_LEFT):
			dirPos = Vector2D(-0.2, 0);
			break;
		default:
			break;
		}
	}
}

bool Paddle::collides(const SDL_Rect& rect) 
{
	SDL_Rect wallRect = {position.getX(), position.getY(), width, height};
	
	if (SDL_HasIntersection(&rect, &wallRect))
		return true;
	else
		return false;
}

SDL_Rect Paddle::rect()
{
	SDL_Rect wallRect = { position.getX(), position.getY(), width, height };

	return wallRect;
}

void Paddle::ballHitsPaddle(const SDL_Rect& ballRect, const SDL_Rect& paddleRect, Vector2D& collVector) {
	int xPaddle = paddleRect.x + paddleRect.w / 2;
	int xBall = ballRect.x + ballRect.w / 2;
	double ang = ((double)(xPaddle - xBall)) / ((double)(paddleRect.w / 2)) / 2;
	collVector = { ang,1 };
}
