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
	//collides();
}

int Paddle::handleEvents(SDL_Event event)
{
	switch (SDL_KEYDOWN)
	{
		case(SDLK_RIGHT):
			{
				position.operator+(Vector2D(1,0));
				return 0;
			}
		case (SDLK_LEFT):
			{
				position.operator+(Vector2D(-1, 0));
				return 0;
			}
		default:
			return 0;
	}
}

bool Paddle::collides(const SDL_Rect& rect) {
	SDL_Rect wallRect = { position.getX(), position.getY(), width, height };
	
	if (SDL_HasIntersection(&rect, &wallRect))
		return true;

	else
		return false;
}
