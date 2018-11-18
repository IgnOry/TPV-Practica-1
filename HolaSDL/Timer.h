#pragma once

#include "Texture.h"
#include "Vector2D.h"

class Timer //ver como se hace la herencia
{
private:
	Texture* texture;
	uint currentTime;
	uint lastTime;
	Vector2D position;
	uint width;
	uint height;
	int timeReset;				// tiempo desde la última muerte
	int ticks = 0;				// ticks totales de la partida, sin contar las muertes (para guardar partida y cargarla)

public:
	Timer(Texture* textureD, Vector2D pos, uint width, uint height, int timeReset, int ticks);
	~Timer();
	void update();
	uint time();				// devuelve el tiempo (para los scores)
	int timeFromDeath();
	void render();
	void resetTime();
};

