#include "Timer.h"



Timer::Timer(Texture* textureD, Vector2D pos, uint Width, uint Height, int timereset, int tks)
{
	texture = textureD;
	position = pos;
	width = Width;
	height = Height;
	timeReset = timereset;
	ticks = tks;
}


Timer::~Timer()
{
}

void Timer::update()
{
	currentTime = (SDL_GetTicks()/1000) + ticks - timeReset;		// tiempo del juego actual + tiempo de la partida guardada - tiempo desde que moriste
	if (currentTime > lastTime + 1000) {
		lastTime = currentTime;
	}
}

uint Timer::time()
{
	return currentTime;
}

int Timer::timeFromDeath(){
	return timeReset;
}

void Timer::render()
{
	SDL_Rect srcRectDecMin = { position.getX(), position.getY(), width, height };	//decenas de minutos
	SDL_Rect srcRectMin = { position.getX() + width, position.getY(), width, height };	//minutos

	SDL_Rect srcRectSeparador = { position.getX() + width * 2, position.getY(), width, height };	//:

	SDL_Rect srcRectDecSec = {position.getX() + width * 3, position.getY(), width, height };	//decenas de segundo
	SDL_Rect srcRectSec = { position.getX() + width * 4, position.getY(), width, height };	//segundos

	texture->renderFrame(srcRectSec,0, (currentTime%10));	//segundos
	texture->renderFrame(srcRectDecSec, 0, (currentTime / 10) % 6);	//decenas de segundo
	texture->renderFrame(srcRectSeparador, 0, 10);	//:
	texture->renderFrame(srcRectMin, 0, (currentTime / 60) % 10);	//minutos
	texture->renderFrame(srcRectDecMin, 0, (currentTime / 600) % 10);	//decenas de minutos
}

void Timer::reset()
{
	timeReset = SDL_GetTicks() / 1000;
}


