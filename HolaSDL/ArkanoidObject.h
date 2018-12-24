#pragma once
#include "Vector2D.h"
#include "checkML.h"
#include "SDLGameobject.h"
#include "Texture.h"
#include <string>


class ArkanoidObject: public SDLGameObject
{
public:
	ArkanoidObject();
	ArkanoidObject(Vector2D pos, int w, int h, Texture *tx);
	virtual ~ArkanoidObject();
	virtual void loadFromFile(ifstream& file);
	virtual void saveToFile(ofstream& file);
	virtual bool handleEvent(SDL_Event e);
	Vector2D getPosition();
};

