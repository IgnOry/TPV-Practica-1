#pragma once
#include "Vector2D.h"
#include "checkML.h"
#include "GameObject.h"
#include "Texture.h"
#include <iostream>
#include <fstream>
#include <string>


class ArkanoidObject: public GameObject
{
public:
	ArkanoidObject();
	~ArkanoidObject();
	void loadFromFile();
	void saveToFile();
	SDL_Rect getRect();
protected: 
	Vector2D position;
	uint width;
	uint height;
	Texture* texture;
};

