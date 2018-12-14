#include "SDLGameObject.h"


SDLGameObject::SDLGameObject(uint w, uint h, Texture* txt, Vector2D pos) :GameObject()
{
	position = pos;
	width = w;
	height = h;
	texture = txt;
}

void SDLGameObject::render()
{
}

void SDLGameObject::update()
{
}


SDLGameObject::~SDLGameObject()
{
}