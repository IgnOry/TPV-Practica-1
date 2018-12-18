#pragma once
#include"GameState.h"

class MainMenuState : public GameState
{
public:
	MainMenuState(Game* g);
	~MainMenuState();

	static void play(Game * game);
	static void load(Game* game);
	static void exit(Game* game);

private:
	Game* game;
	Button* newGameB;
	Button* loadGameB;
	Button* exitB;
};