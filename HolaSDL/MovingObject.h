#pragma once
#include "Vector2D.h"
#include "checkML.h"
#include "ArkanoidObject.h"
#include <iostream>
#include <fstream>
#include <string>


class MovingObject: public ArkanoidObject
{
public:
	MovingObject(Vector2D pos, int width, int height, Texture * texture, Vector2D dirPos);
	~MovingObject();
	Vector2D getDirection();
	void loadFromFile(string filepath);
	void update();

protected:
	Vector2D dirPos;
};

