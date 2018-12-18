#include "SDLGameObject.h"
#include "SDL_ttf.h"

SDLGameObject::SDLGameObject(uint w, uint h, Texture* txt, Vector2D pos) :GameObject()
{
	position = pos;
	width = w;
	height = h;
	texture = txt;
}

void SDLGameObject::render()
{
	texture->render(getRect());
}

void SDLGameObject::update()
{
}

SDL_Rect SDLGameObject::getRect()
{
	SDL_Rect rect = { position.getX(), position.getY(), width, height };
	return rect;
}


SDLGameObject::~SDLGameObject()
{
}