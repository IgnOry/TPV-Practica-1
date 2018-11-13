#pragma once
#include "checkML.h"

class BestPlayers
{
public:
	BestPlayers(const int levs);
	~BestPlayers();
	void PrintList();
	void CompareTimes(const int time);
private:
	int levels;
};

