#pragma once
#include "Texture.h"
#include "GameObject.h"
#include "Vector2D.h"

typedef unsigned int uint;

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(uint w, uint h, Texture* txt, Vector2D pos);
	virtual bool handleEvent(SDL_Event e) = 0;
	virtual void render();
	virtual void update();
	~SDLGameObject();

protected:
	uint width;
	uint height;
	Texture* texture;
	Vector2D position;
};