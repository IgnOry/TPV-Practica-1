#pragma once

#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include <string>
#include "Vector2D.h"
#include "checkML.h"
#include "MovingObject.h"


class Game;

class Ball: public MovingObject
{
	//hereda todos los atributos restantes de ArkanoidObject y MovingObject


private:
		Game* ptrGame;
public:
	Ball(Vector2D pos, uint widthN, uint heightN, Vector2D direction, Texture* ptrTextureD, Game* ptrGameD);
	~Ball();
	virtual void render();
	virtual void update();
};

