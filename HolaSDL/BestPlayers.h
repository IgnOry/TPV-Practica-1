#pragma once
#include "checkML.h"
#include "ArkanoidObject.h"

class BestPlayers: public ArkanoidObject
{
public:
	BestPlayers(const int levs);
	~BestPlayers();
	void PrintList();
	void CompareTimes(const int time);
private:
	int levels;
};

