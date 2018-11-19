#pragma once
#include "Vector2D.h"
#include "checkML.h"
#include "ArkanoidObject.h"
#include <iostream>
#include <fstream>

class MovingObject: public ArkanoidObject
{
public:
	MovingObject(Vector2D pos, int width, int height, Texture * texture,Vector2D dirPos):ArkanoidObject(pos, width, height, texture);
	~MovingObject();
	Vector2D getDirection();
	void loadFromFile(ifstream file);
	void update();

protected:
	Vector2D dirPos;
};

