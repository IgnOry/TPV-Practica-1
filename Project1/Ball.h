#pragma once

#include "Vector2D.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"

#include <string>

class Game;


class Ball
{

private:
		Vector2D position;
		uint width;
		uint height;
		Vector2D dirPos;
		Texture* ptrTexture;
		Game* ptrGame;
public:
	Ball(Vector2D pos, uint widthN, uint heightN, Vector2D direction, Texture* ptrTextureD, Game* ptrGameD);
	~Ball();
	void render();
	void update();
};

