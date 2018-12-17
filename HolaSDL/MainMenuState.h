#pragma once
#include"GameState.h"

class MainMenuState : public GameState
{
public:
	MainMenuState(Game* g, Texture* texture);
	void NewGame();
	~MainMenuState();

private:
	Button* newGame;
	Button* loadGame;
	Button* exit;
};