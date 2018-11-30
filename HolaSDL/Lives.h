#pragma once
#include "ArkanoidObject.h"

class Lives: public ArkanoidObject
{
public:
	Lives();
	~Lives();
	uint current();
	void less();
private:
	uint lives;
};

