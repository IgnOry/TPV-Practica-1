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
	ArkanoidObject(Vector2D pos, int w, int h, Texture *tx);
	~ArkanoidObject();
	void loadFromFile(ifstream file);
	void saveToFile();
	SDL_Rect getRect();
	Vector2D getPosition();
	void render();

protected: 
	Vector2D position;
	uint width;
	uint height;
	Texture* ptrTexture;
};

