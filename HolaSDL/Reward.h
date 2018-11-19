#pragma once
#include "checkML.h"
#include "MovingObject.h"

class Reward: public MovingObject
{
public:
	Reward(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction);
	~Reward();
};

