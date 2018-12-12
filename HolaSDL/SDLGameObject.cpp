#include "SDLGameObject.h"



SDLGameObject::SDLGameObject(uint w, uint h, Texture* txt,Vector2D pos):GameObject()
{
	position = pos;
	width = w;
	height = h;
	texture = txt;
}

bool SDLGameObject::handleEvent(SDL_Event e)
{
	return false;
}


SDLGameObject::~SDLGameObject()
{
}

void SDLGameObject::render()
{
}

void SDLGameObject::update()
{
}

