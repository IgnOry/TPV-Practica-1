#pragma once

#include "Texture.h"
#include "Vector2D.h"

class Timer
{
private:
	Texture* texture;
	uint currentTime;
	uint lastTime;
	Vector2D position;
	uint width;
	uint height;
	int timeReset;
	int ticks = 0;

public:
	Timer(Texture* textureD, Vector2D pos, uint width, uint height, uint lasttime, int timeReset, int ticks);
	~Timer();
	void update();
	uint time();
	int timeFromDeath();
	void render();
	void resetTime();
};

