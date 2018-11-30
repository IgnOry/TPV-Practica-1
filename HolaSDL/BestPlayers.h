#pragma once
#include "checkML.h"
#include "ArkanoidObject.h"

class BestPlayers: public ArkanoidObject
{
public:
	BestPlayers(const int levs);
	~BestPlayers();
	void PrintList();
	virtual void saveToFile();
	virtual void loadFromFile();
	void CompareTimes(const uint time);
private:
	int levels;
	int topScores[10];		//valor por defecto de los scores: -1
};

