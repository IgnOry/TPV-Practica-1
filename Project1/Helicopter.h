#pragma once

#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"

#include <string>

using namespace std;

typedef unsigned int uint;

class Helicopter
{
private:
	uint w = 0; // width
	uint h = 0; // height
	uint x = 0;
	uint y = 0; // Posición de esquina superior izqda
	int dirX = 0;
	int dirY = 0;
	// Dirección de movimiento
	Texture* texture = nullptr;

public:
	Helicopter() {}
	Helicopter(uint w, uint h, uint x, uint y, Texture* t) :
		w(w), h(h), x(x), y(y), texture(t) {}

	~Helicopter() {}
	void render() const;
	void update();
	void handleEvents(SDL_Event& event);
};

