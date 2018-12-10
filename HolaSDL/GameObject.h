#pragma once
#include "checkML.h"
#include "SDL.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void render();
	virtual void update();
	virtual void handleEvents(SDL_Event event);
};

