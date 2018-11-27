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
	virtual ~ArkanoidObject();
	virtual void loadFromFile(ifstream& file);
	virtual void saveToFile(ofstream& file);
	SDL_Rect getRect();
	Vector2D getPosition();
	virtual void render();

protected: 
	Vector2D position;
	uint width;
	uint height;
	Texture* ptrTexture;
};

