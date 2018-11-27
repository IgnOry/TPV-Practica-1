#pragma once
#include "checkML.h"
#include "MovingObject.h"

class Reward: public MovingObject
{
public:
	Reward(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction);
	~Reward();
	void render();
	virtual void behavior() {};
protected:
	int frame =0;
};

class Reward1 : public Reward
{
public:
	Reward1(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction);
	~Reward1();
};

class Reward2 : public Reward
{
public:
	Reward2(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction);
	~Reward2();
};

class Reward3 : public Reward
{
public:
	Reward3(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction);
	~Reward3();
};

