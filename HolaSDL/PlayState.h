#pragma once
#include "GameState.h"

class PlayState : public GameState
{
public:
	PlayState(Game* g);
	~PlayState();
	void handleEvents(SDL_Event e); //habría que cambiar a bool todos los handleEvents

};