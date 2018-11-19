#include "Paddle.h"

Paddle::Paddle(Vector2D pos, uint wid, uint heightD, Vector2D direction, Texture* ptr):MovingObject()
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



void Paddle::handleEvents(SDL_Event event)
{
	if(event.type == SDL_KEYUP)
		dirPos = Vector2D(0, 0);
	else {
		switch (event.key.keysym.sym)
		{
		case(SDLK_RIGHT):
			dirPos = Vector2D(0.8, 0);
			break;

		case (SDLK_LEFT):
			dirPos = Vector2D(-0.8, 0);
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

void Paddle::ballHitsPaddle(const SDL_Rect& ballRect, Vector2D& collVector) {
	SDL_Rect paddleRect = {position.getX(), position.getY(), width, height };

	int xPaddle = paddleRect.x + paddleRect.w / 2;
	int xBall = ballRect.x + ballRect.w / 2;

	if(xBall - xPaddle <= -(paddleRect.w / 6))	//izda
		collVector = { -1,-5 };
	else if (xBall - xPaddle >= (paddleRect.w / 6))	//drcha
		collVector = { 1,-5 };
	else  collVector = { 0,-2 };	//centro
		
}

