#include "BestPlayers.h"
#include <iostream>
#include <fstream>
#include <string>



BestPlayers::BestPlayers(const int levs)
{
	levels = levs;
}


BestPlayers::~BestPlayers()
{
}

void BestPlayers::PrintList() {
	
	loadFromFile();

	for (int i = 0; i < 10; i++)
	{
		cout << i << ". " << topScores[i] << endl;
	}
}

void BestPlayers::saveToFile()
{
	uint level;
	cin >> level;
	string filepath = "..\\bestPlayers\\level" + std::to_string(level) + ".ark";
	ofstream FileData(filepath);

	for (int i = 0; i < 10; i++)
	{
		FileData << topScores[i];
	}
}

void BestPlayers::loadFromFile()
{
	uint level;
	cin >> level;

	string filepath = "..\\bestPlayers\\level" + std::to_string(level) + ".ark";
	ifstream FileData(filepath);

	for (int i = 0; i < 10; i++)
	{
		FileData >> topScores[i];
	}
}

void BestPlayers::CompareTimes(const uint time) {
	
	if (topScores[9] > 0) //esto quiere decir que todos los puestos del ranking están ocupados
	{
		int i = 0;

		while (topScores[i] < time && i < std::size(topScores)) //no comprobado
			i++;

		if (i < std::size(topScores))
		{
			topScores[i] = time;
			saveToFile();
		}
	}

	else
	{
		int i = 0;

		while (topScores[i] < 0) //si no lo están, busca el primero libre
			i++;

		topScores[i] = time;
	}
}
