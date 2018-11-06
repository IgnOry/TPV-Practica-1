#include "Timer.h"



Timer::Timer(Texture* textureD, Vector2D pos, uint Width, uint Height)
{
	texture = textureD;
	position = pos;
	width = Width;
	height = Height;
}


Timer::~Timer()
{
}

void Timer::update()
{
	currentTime = SDL_GetTicks()/1000;
	if (currentTime > lastTime + 1000) {
		lastTime = currentTime;
	}
}

void Timer::render()
{
	SDL_Rect srcRect = {position.getX(), position.getY(), width, height };

	texture->renderFrame(srcRect, (currentTime%10) / texture->getNumCols(), 1);

}
