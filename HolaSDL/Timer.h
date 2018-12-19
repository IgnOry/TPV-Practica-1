#pragma once
#include "checkML.h"

#include "Texture.h"
#include "Vector2D.h"
#include "ArkanoidObject.h"

class Timer: public ArkanoidObject //ver como se hace la herencia
{
private:
	uint currentTime;
	uint lastTime;
	int timeReset;				// tiempo desde la última muerte
	int ticks = 0;				// ticks totales de la partida, sin contar las muertes (para guardar partida y cargarla)

public:
	Timer(Vector2D pos, uint width, uint height, Texture* textureD, int timeReset, int ticks);
	~Timer();
	void update();
	uint time();				// devuelve el tiempo (para los scores)
	int timeFromDeath();
	void render();
	void reset();
	void saveToFile(ofstream & file);
	void loadFromFile(ifstream & file);
};

