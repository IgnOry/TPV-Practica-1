#pragma once
#include "checkML.h"
#include "MovingObject.h"
#include <list>

class Game;

class Reward: public MovingObject
{
private:
	uint tipo; //de 0 a ?? para ver que tipo de Reward es
public:
	Reward(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction, PlayState* ptrGameD);
	~Reward();
	void render();
	void update();
	virtual void behavior();
	virtual bool handleEvent();
	list<ArkanoidObject*>::iterator it;
protected:
	int numReward = 0;
	int frame = 0;
	PlayState* ptrGame;
};

class Reward1 : public Reward
{
public:
	Reward1(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction, PlayState* ptrGameD);
	virtual void behavior() ;

	~Reward1();
};

class Reward2 : public Reward
{
public:
	Reward2(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction, PlayState* ptrGameD);
	virtual void behavior();

	~Reward2();
};

class Reward3 : public Reward
{
public:
	Reward3(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction, PlayState* ptrGameD);
	virtual void behavior();

	~Reward3();
};

class Reward4 : public Reward
{
public:
	Reward4(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction, PlayState* ptrGameD);
	virtual void behavior();

	~Reward4();
};

