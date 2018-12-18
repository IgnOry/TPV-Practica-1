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
	Button(uint w, uint h, Texture* txt, Vector2D pos, Game* g, CallBackOnClick cb);
	~Button();
	virtual bool handleEvent(SDL_Event e);
};