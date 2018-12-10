#pragma once
#include "Texture.h"
#include "GameObject.h"
#include "Vector2D.h"

typedef unsigned int uint;

class SDLGameObject: public GameObject
{
public:
	SDLGameObject(uint w, uint h, Texture* txt, double x, double y);
	virtual bool handleEvents(SDL_Event e); //habr�a que cambiar a bool todos los handleEvents
	~SDLGameObject();

protected:
	uint width;
	uint height;
	Texture* texture;
	Vector2D position;
};

