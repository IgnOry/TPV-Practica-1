#include "Button.h"


Button::Button(Vector2D pos, uint w, uint h, Texture* tx, Game* g, CallBackOnClick callback):SDLGameObject(pos, w, h, tx)
{
	app = g;
	cb = callback;
}

Button::Button(Vector2D pos, uint w, uint h, Texture* tx, Game* g, PlayState* state, CallBackOnClick callback) :SDLGameObject(pos, w, h, tx)
{
	app = g;
	cb = callback;
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
