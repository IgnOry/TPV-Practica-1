#pragma once
#include "SDLGameObject.h"
#include "Game.h"

using CallBackOnClick = void(Game* g);

class Button: public SDLGameObject
{
public:
	Button(uint w, uint h, Texture* txt, Vector2D pos, Game* g , CallBackOnClick cb);
	~Button();
	virtual bool handleEvent(SDL_Event e);
protected:
	CallBackOnClick* cb;
	Game* app;
};

