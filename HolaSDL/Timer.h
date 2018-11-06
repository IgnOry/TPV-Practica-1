#pragma once

#include "Texture.h"
#include "Vector2D.h"

class Timer
{
private:
	Texture* texture;
	uint currentTime;
	uint lastTime = 0;
	Vector2D position;
	uint width;
	uint height;

public:
	Timer(Texture* textureD, Vector2D pos, uint width, uint height);
	~Timer();
	void update();
	void render();
};

