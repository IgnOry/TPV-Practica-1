#pragma once
#include "Vector2D.h"
#include "checkML.h"

class ArkanoidObject
{
public:
	ArkanoidObject();
	~ArkanoidObject();
	void loadFromFile();
	void saveToFile();
	void getRect();
private: 
	Vector2D position;
//	uint width;
	//uint height;
//	Texture* texture;
};

