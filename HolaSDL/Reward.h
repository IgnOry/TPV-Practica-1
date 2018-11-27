#pragma once
#include "checkML.h"
#include "MovingObject.h"

class Reward: public MovingObject
{
private:
	uint tipo; //de 0 a ?? para ver que tipo de Reward es
public:
	Reward(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction, uint Tipo);
	~Reward();
	//Efectos Rewards
};

