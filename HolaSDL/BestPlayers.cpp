#include "BestPlayers.h"
#include <iostream>
#include <fstream>
#include <string>



BestPlayers::BestPlayers(const int levs): ArkanoidObject()
{
	levels = levs;
}


BestPlayers::~BestPlayers()
{
}

void BestPlayers::PrintList() {

}

void BestPlayers::CompareTimes(const int time) {
	
	
	//ifstream FileData(top[level]);

	int topScores[10];		//valor por defecto de los scores: -1

	for (int i = 0; i < 10; i++)
	{
		//cin >> topScores[i];
	}

	if (topScores[9] > 0)
	{
		int i = 0;

		while (topScores[i] < time)
			i++;

		topScores[i] = time;
	}

	else
	{
		int i = 0;

		while (topScores[i] < 0)
			i++;

		topScores[i] = time;
	}
}
