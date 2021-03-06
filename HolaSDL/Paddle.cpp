#include "Paddle.h"

Paddle::Paddle(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction):MovingObject(pos, wid, heightD, ptr, direction)
{
	originalSize = wid;
}

Paddle::~Paddle()
{
}

void Paddle::update()
{
	if (position.getX() >= 20 && (position.getX() + width) < 780)
		MovingObject::update();
	else
	{
		if (position.getX() < 20)
		{
			position = position + Vector2D(1, 0);
			dirPos = Vector2D(0, 0);
		} 
		else {
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
			dirPos = Vector2D(0.4, 0);
			break;

		case (SDLK_LEFT):
			dirPos = Vector2D(-0.4, 0);
			break;
		default:
			break;
		}
	}
}

void Paddle::longer() {
	int var = 10;
	if(width < (originalSize + var * 5))
		width += var;
} 

void Paddle::shorter() {
	int var = 25;
	if (width > (originalSize - var * 3))
		width -= var;
}

void Paddle::reset(Vector2D pos, Vector2D dir)
{
	width = originalSize;
	MovingObject::reset(pos, dir);
}

bool Paddle::collides(const SDL_Rect& rect) 
{
	SDL_Rect wallRect = getRect();
	
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

