#pragma once
#include "checkML.h"
#include "SDL.h"
#include <iostream>
#include <fstream>

using namespace std;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void render() = 0;
	virtual void update() = 0;
	virtual bool handleEvent(SDL_Event event) = 0;
	virtual SDL_Rect getRect() = 0;

	//necesarios para la lista stage, declarados como vacíos, puede ser necesario hacerlos abstractos
	virtual void loadFromFile(ifstream& file);
	virtual void saveToFile(ofstream& file);
};