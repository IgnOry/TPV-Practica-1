#pragma once
#include "GameState.h"

class PlayState : public GameState
{
public:
	PlayState(Game* g);
	~PlayState();
	virtual bool handleEvent(SDL_Event e);

};