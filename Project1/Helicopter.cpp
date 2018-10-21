#include "Helicopter.h"

void Helicopter::render() const
{
	texture->load("..\\images\\helicopter.png", 6, 1);

	SDL_Rect destRect = { x, y, w, h };

	texture->render(destRect, SDL_FLIP_NONE);
}

void Helicopter::update()
{
	x = x + dirX;
	y = y + dirY;
}

void Helicopter::handleEvents(SDL_Event & event)
{
	if (event.type == SDLK_j)
		dirX++;

	if (event.type == SDLK_g)
		dirX--;

	if (event.type == SDLK_h)
	{
		dirX = 0;
		dirY = 0;
	}
}
