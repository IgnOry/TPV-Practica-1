#include "SDLGameObject.h"
#include "SDL_ttf.h"

SDLGameObject::SDLGameObject()
{}

SDLGameObject::SDLGameObject(Vector2D pos, int w, int h, Texture *tx) :GameObject()
{
	position = pos;
	width = w;
	height = h;
	texture = tx;
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