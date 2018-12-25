#pragma once
#include "GameState.h"

class PlayState;

class PauseState : public GameState
{
public:
	PauseState(Game* g, PlayState* state);
	virtual bool handleEvent(SDL_Event e);
	~PauseState();

	static void resume(Game* app);
	static void menu(Game * app);
	static void save(Game * app);
private:
	Game* game;
	Button* resumeB;
	Button* saveB;
	Button* menuB;
	PlayState* pState;
};