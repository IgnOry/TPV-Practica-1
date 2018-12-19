#pragma once

#include "Vector2D.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include "checkML.h"
#include "ArkanoidObject.h"


class Wall: public ArkanoidObject
{

	//hereda todos los atributos de ArkanoidObject

public:
	Wall(Vector2D pos, int width, int height, Texture* texture);
	~Wall();
};

