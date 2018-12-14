#pragma once
#include "GameState.h"

class PauseState : public GameState
{
public:
	PauseState(Game* g);
	~PauseState();

	static void resume(Game* app);
};