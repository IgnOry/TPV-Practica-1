#pragma once
#include "SDLGameObject.h"

class Game;

using CallBackOnClick = void(Game* g);

class Button : public SDLGameObject
{
protected:
	CallBackOnClick* cb;
	Game* app;
public:
	Button(Vector2D pos, uint w, uint h, Texture* tx, Game* g, CallBackOnClick callback);
	~Button();
	virtual bool handleEvent(SDL_Event e);
};