#pragma once
#include "ArkanoidObject.h"

class Lives: public ArkanoidObject
{
public:
	Lives();
	~Lives();
	uint current();
	void less();
	virtual void render();
private:
	uint lives;
};

