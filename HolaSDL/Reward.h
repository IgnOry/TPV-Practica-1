#pragma once
#include "checkML.h"
#include "MovingObject.h"
#include <list>

class Game;

class Reward: public MovingObject
{
public:
	Reward(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction, Game* ptrGameD);
	~Reward();
	void render();
	void update();
	virtual void behavior();
	list<ArkanoidObject*>::iterator it;
protected:
	int frame = 0;
	Game* ptrGame;
};

class Reward1 : public Reward
{
public:
	Reward1(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction, Game* ptrGameD);
	virtual void behavior() ;

	~Reward1();
};

class Reward2 : public Reward
{
public:
	Reward2(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction, Game* ptrGameD);
	virtual void behavior();

	~Reward2();
};

class Reward3 : public Reward
{
public:
	Reward3(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction, Game* ptrGameD);
	virtual void behavior();

	~Reward3();
};

