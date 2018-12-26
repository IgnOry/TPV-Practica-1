#include "Reward.h"
#include "PlayState.h"

Reward::Reward(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction, PlayState* pState) :MovingObject(pos, wid, heightD, ptr, direction)
{
	state = pState;
}

Reward::~Reward()
{
}

void Reward::render() {
	texture->renderFrame(getRect(), numReward -1, (frame/ 80) % 8);
	frame++;
}

void Reward::update()
{
	MovingObject::update();

	if (state->rewardCollides(getRect(),it))
		behavior();
}

void Reward::behavior()
{
	state->deleteList(it);
	//delete &it;
	//borrar de la lista
	//iterador a null
	//delete this;
}

bool Reward::handleEvent()
{
	return false;
}

// Reward1
Reward1::Reward1(Vector2D pos, uint wid, uint heightD, Texture * ptr, Vector2D direction, PlayState* ptrGameD):Reward(pos, wid, heightD,ptr, direction, ptrGameD)
{
	numReward = 1;
}

void Reward1::behavior()
{
	cout << "1 shorter paddle" << endl;
	state->paddleShorter();
	Reward::behavior();
}

Reward1::~Reward1()
{
}

// Reward2
Reward2::Reward2(Vector2D pos, uint wid, uint heightD, Texture * ptr, Vector2D direction, PlayState* ptrGameD) :Reward(pos, wid, heightD, ptr, direction, ptrGameD)
{
	numReward = 2;
}

void Reward2::behavior()
{
	state->moreLives();
	cout << "2 +vidas" << endl;
	Reward::behavior();
}

Reward2::~Reward2()
{
}

// Reward3
Reward3::Reward3(Vector2D pos, uint wid, uint heightD, Texture * ptr, Vector2D direction, PlayState* ptrGameD) :Reward(pos, wid, heightD, ptr, direction, ptrGameD)
{
	numReward = 3;
}

void Reward3::behavior()
{
	cout << "3 longer paddle" << endl;
	state->paddleLonger();
	Reward::behavior();
}

Reward3::~Reward3()
{
}

// Reward4
Reward4::Reward4(Vector2D pos, uint wid, uint heightD, Texture * ptr, Vector2D direction, PlayState* ptrGameD) :Reward(pos, wid, heightD, ptr, direction, ptrGameD)
{
	numReward = 4;
}

void Reward4::behavior()
{
	cout << "Next Level" << endl;
	Reward::behavior();
	state->PassLevel();
}

Reward4::~Reward4()
{
}