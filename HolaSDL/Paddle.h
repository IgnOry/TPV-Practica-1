#pragma once

#include "Vector2D.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"

#include <string>

class Paddle
{

private:
	Vector2D position;
	uint width;
	uint height;
	Vector2D dirPos;
	Texture* ptrTexture;

public:
	Paddle(Vector2D pos, uint width, uint height, Vector2D direction, Texture* ptr);
	~Paddle();
	void render();
	void update();
	void handleEvents(SDL_Event event);
	bool collides(const SDL_Rect& rect);
	SDL_Rect rect();
	void ballHitsPaddle(const SDL_Rect & ballRect, const SDL_Rect & paddleRect, Vector2D& collVector);
};

