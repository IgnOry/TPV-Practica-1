#pragma once
#include "ArkanoidObject.h"

class Lives: public ArkanoidObject
{
public:
	Lives(Vector2D pos, int width, int height, Texture* texture);
	~Lives();
	uint getLives();
	void less();
	void more();
	void reset();
	virtual void render();
private:
	uint maxLives = 7;
	uint lives;
	uint originalLives;
};

