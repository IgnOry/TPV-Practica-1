#pragma once

#include "Vector2D.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include <string>
#include "checkML.h"
#include "ArkanoidObject.h"



class Block: public ArkanoidObject
{
	//hereda todos los atributos restantes de ArkanoidObject y MovingObject

private:
	uint colour;
	uint rows;
	uint columns;

public:
	Block(Vector2D pos, int widthN, int heightN, int colourN, int columnN, int rowN, Texture* texture);
	void render();
	~Block();
	uint getY();
	uint getX();
	uint getH();
	uint getW();
	int getColour();
	uint row();
	uint colum();
	virtual bool handleEvent(SDL_Event e);

};

