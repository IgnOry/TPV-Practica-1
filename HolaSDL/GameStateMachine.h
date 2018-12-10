#pragma once
#include <stack>
#include "GameState.h"

class GameStateMachine
{
public:
	stack<GameState> stack;

	GameStateMachine();
	~GameStateMachine();
	
	GameState currentState();
	void pushState();
	void changeState();
	void popState();
};

