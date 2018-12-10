#pragma once
#include "SDLGameObject.h"
#include "Game.h"

using CallBackOnClick = void(Game* g);

class Button: public SDLGameObject
{
public:
	Button(Game* g, ...,cb);
	~Button();
	bool handleEvent(SDL_Event e);

protected:
	CallBackOnClick cb;
};

