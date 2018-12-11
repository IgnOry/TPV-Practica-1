#include "Button.h"


Button::Button(uint w, uint h, Texture* txt, Vector2D pos, Game* g, CallBackOnClick cb):SDLGameObject(w, h, txt, pos)
{
	app = g;
}

Button::~Button()
{
}

bool Button::handleEvent(SDL_Event e)
{
	bool handled = false;
	if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT)
	{
		SDL_Point p = { e.button.x, e.button.y };
		SDL_Rect r = { position.getX(), position.getY(), width, height };

		if (SDL_PointInRect(&p, &r))
		{
			cb(app);
			cout << "botón pulsado\n";
			handled = true;
		}
	}
	return handled;
}
