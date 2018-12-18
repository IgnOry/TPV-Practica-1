#pragma once
#include"GameState.h"
class EndState: public GameState
{
public:
	EndState(Game* g);
	~EndState();

	static void menu(Game * game);
	static void exit(Game * game);

private:
	Game* game;
	Button* exitB;
	Button* menuB;
};