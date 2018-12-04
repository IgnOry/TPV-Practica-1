#pragma once

#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include <string>
#include "Vector2D.h"
#include "checkML.h"
#include "MovingObject.h"
class Enemy:public MovingObject
{
public:
	Enemy(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction);
	~Enemy();
	virtual void update();
	virtual void render();
private:
	int frame = 0;
};

