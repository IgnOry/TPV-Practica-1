#pragma once
#include "Vector2D.h"
#include "checkML.h"
#include "GameObject.h"
#include "Texture.h"


class ArkanoidObject: public GameObject
{
public:
	ArkanoidObject();
	~ArkanoidObject();
	void loadFromFile();
	void saveToFile();
	void getRect();
protected: 
	Vector2D position;
	uint width;
	uint height;
	Texture* texture;
};

