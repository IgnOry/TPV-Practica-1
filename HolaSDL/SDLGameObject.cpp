#include "SDLGameObject.h"



SDLGameObject::SDLGameObject(uint w, uint h, Texture* txt, double x, double y):GameObject()
{
	position = Vector2D(x, y);
	width = w;
	height = h;
	texture = txt;
}

void SDLGameObject::handleEvents(SDL_Event e) //habría que cambiar a bool todos los handleEvents
{
	if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT)
	{

		SDL_Point p = { e.button.x, e.button.y};
		SDL_Rect r = {position.getX(), position.getY(), width, height};

		if (SDL_PointInRect(&p, &r))
		{
			//callback
			cout << "";
			//return
		}
	}
}


SDLGameObject::~SDLGameObject()
{
}

