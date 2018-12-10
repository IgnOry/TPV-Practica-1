#pragma once
#include "GameObject.h"
#include "Game.h"
#include <list>

using namespace std;

class GameState
{
protected:
	list<GameObject*> stage;
	Game* app;
public:
	GameState();
	~GameState();
	virtual void update();
	virtual void handleEvents(SDL_Event e);
	virtual void render();
};