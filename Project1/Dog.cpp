#include "Dog.h"

void Dog::render() const
{
	texture->load("..\\images\\dog.png", 6, 1);

	SDL_Rect destRect = {x, y, w, h };

	texture->render(destRect, SDL_FLIP_NONE);
}

void Dog::update()
{
	x = x + dirX;
	y = y + dirY;
}

void Dog::handleEvents(SDL_Event & event)
{
	if (event.type == SDLK_f)
	{
		dirX++;
	}

	if (event.type == SDLK_s)
	{
		dirX--;
	}

	if (event.type == SDLK_d)
	{
		dirX = 0;
		dirY = 0;
	}

}