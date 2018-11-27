#include "Reward.h"

Reward::Reward(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction, uint Tipo) :MovingObject(pos, wid, heightD, ptr, direction)
{
	tipo = Tipo;
}

Reward::~Reward()
{
}

//Efectos Rewards
