#pragma once
#include "GameState.h"

class PauseState : public GameState
{
public:
	PauseState(Game* g, Texture* texture1, Texture* texture2, Texture* texture3, CallBackOnClick* cb);
	~PauseState();

	static void resume(Game* app);
	static void menu(Game * app);
	static void save(Game * app);
private:
	Game* game;
	Button* resumeB;
	Button* saveB;
	Button* menuB;
};