#pragma once

#include "Vector2D.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"

#include <string>
#include "checkML.h"
#include "MovingObject.h"


class Paddle: public MovingObject
{
	//hereda todos los atributos de ArkanoidObject y MovingObject
public:
	Paddle(Vector2D pos, uint width, uint height, Vector2D direction, Texture* ptr);
	~Paddle();
	void render();
	void update();
	void handleEvents(SDL_Event event);
	bool collides(const SDL_Rect& rect);
	SDL_Rect rect();
	void ballHitsPaddle(const SDL_Rect & ballRect, Vector2D& collVector);
};

