#pragma once
#include "GameObject.h"
#include "Game.h"
#include <list>
#include "Button.h"

using namespace std;

class GameState
{
protected:
	list<GameObject*> stage;
	Game* app;
public:
	GameState(Game* g);
	virtual ~GameState();
	virtual void update();
	virtual bool handleEvent(SDL_Event e);
	virtual void render();
};