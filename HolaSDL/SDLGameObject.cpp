#include "SDLGameObject.h"



SDLGameObject::SDLGameObject(uint w, uint h, Texture* txt, double x, double y):GameObject()
{
	position = Vector2D(x, y);
	width = w;
	height = h;
	texture = txt;
}

bool SDLGameObject::handleEvent(SDL_Event e) //habr�a que cambiar a bool todos los handleEvents
{
	
}


SDLGameObject::~SDLGameObject()
{
}

