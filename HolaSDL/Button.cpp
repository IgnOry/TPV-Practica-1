#include "Button.h"


Button::Button(Game * g, ..., cb)
{
}

Button::~Button()
{
}

bool Button::handleEvent(SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT)
	{

		SDL_Point p = { e.button.x, e.button.y };
		SDL_Rect r = { position.getX(), position.getY(), width, height };

		if (SDL_PointInRect(&p, &r))
		{
			cb(g);
			cout << "";
			handled = true;
		}
	}

	return handled;
}
