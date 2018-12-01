#include "Reward.h"
#include "Game.h"

Reward::Reward(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction, Game* ptrGameD) :MovingObject(pos, wid, heightD, ptr, direction)
{
	ptrGame = ptrGameD;
}


Reward::~Reward()
{
}

void Reward::render() {
	ptrTexture->renderFrame(getRect(), 0, (frame/ 80) % 8);
	frame++;
}

void Reward::update()
{
	MovingObject::update();

	if (ptrGame->rewardCollides(getRect()))
		behavior();
}

void Reward::behavior()
{
	ptrGame->deleteList(it);
	//delete &it;
	//borrar de la lista
	//iterador a null
	//delete this;
}

// Reward1
Reward1::Reward1(Vector2D pos, uint wid, uint heightD, Texture * ptr, Vector2D direction, Game* ptrGameD):Reward(pos, wid, heightD,ptr, direction, ptrGameD)
{
}

void Reward1::behavior()
{
	cout << "1" << endl;
	Reward::behavior();
}

Reward1::~Reward1()
{
}

// Reward2
Reward2::Reward2(Vector2D pos, uint wid, uint heightD, Texture * ptr, Vector2D direction, Game* ptrGameD) :Reward(pos, wid, heightD, ptr, direction, ptrGameD)
{
}

void Reward2::behavior()
{
	cout << "2" << endl;
	ptrGame->moreLives();
	Reward::behavior();
}

Reward2::~Reward2()
{
}

// Reward3
Reward3::Reward3(Vector2D pos, uint wid, uint heightD, Texture * ptr, Vector2D direction, Game* ptrGameD) :Reward(pos, wid, heightD, ptr, direction, ptrGameD)
{
}

void Reward3::behavior()
{
	cout << "3" << endl;
	Reward::behavior();
}

Reward3::~Reward3()
{
}
