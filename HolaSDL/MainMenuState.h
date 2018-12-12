#pragma once
#include"GameState.h"

class MainMenuState: public GameState
{
public:
	MainMenuState(Game* g, Texture* texture, CallBackOnClick cb);
	~MainMenuState();

	static void play(Game * game);
private:
	Button* newGame;
	Button* loadGame;
	Button* exit;
	Game* game;
};

