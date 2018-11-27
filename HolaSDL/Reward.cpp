#include "Reward.h"

Reward::Reward(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction) :MovingObject(pos, wid, heightD, ptr, direction)
{
}


Reward::~Reward()
{
}

void Reward::render() {
	ptrTexture->renderFrame(getRect(), 0, (frame/ 80) % 8);
	frame++;
}

Reward1::Reward1(Vector2D pos, uint wid, uint heightD, Texture * ptr, Vector2D direction):Reward(pos, wid, heightD,ptr, direction)
{
}

Reward1::~Reward1()
{
}

Reward2::Reward2(Vector2D pos, uint wid, uint heightD, Texture * ptr, Vector2D direction) :Reward(pos, wid, heightD, ptr, direction)
{
}

Reward2::~Reward2()
{
}

Reward3::Reward3(Vector2D pos, uint wid, uint heightD, Texture * ptr, Vector2D direction) :Reward(pos, wid, heightD, ptr, direction)
{
}

Reward3::~Reward3()
{
}
