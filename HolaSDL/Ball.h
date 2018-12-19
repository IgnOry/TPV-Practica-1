#pragma once

#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include <string>
#include "Vector2D.h"
#include "checkML.h"
#include "MovingObject.h"


class PlayState;

class Ball: public MovingObject
{
private:
		PlayState* state;
		//hereda el resto de los atributos restantes de ArkanoidObject y MovingObject
public:
	Ball(Vector2D pos, uint wid, uint heightD, Texture* ptr, Vector2D direction, PlayState* state);
	~Ball();
	virtual void update();
};

