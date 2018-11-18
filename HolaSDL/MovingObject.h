#pragma once
#include "Vector2D.h"
#include "checkML.h"
#include "ArkanoidObject.h"

class MovingObject: public ArkanoidObject
{
public:
	MovingObject();
	~MovingObject();
	void updateClass();
	Vector2D getDirection();

protected:
	Vector2D dirPos;
};

