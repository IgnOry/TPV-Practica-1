#pragma once
#include "ArkanoidObject.h"

class Lives: public ArkanoidObject
{
public:
	Lives(Vector2D pos, int width, int height, Texture* texture);
	~Lives();
	uint getLives();
	void less();
	virtual void render();
private:
	uint lives;
};

