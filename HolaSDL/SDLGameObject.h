#pragma once
#include "Texture.h"
#include "GameObject.h"
#include "Vector2D.h"

typedef unsigned int uint;

class SDLGameObject : public GameObject
{
public:
	SDLGameObject();
	SDLGameObject(Vector2D pos, int w, int h, Texture *tx);
	virtual bool handleEvent(SDL_Event e) = 0;
	virtual void render();
	virtual void update();
	SDL_Rect getRect();
	~SDLGameObject();

protected:
	uint width;
	uint height;
	Texture* texture;
	Vector2D position;
};