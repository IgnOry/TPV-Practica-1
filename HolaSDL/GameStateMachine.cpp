#include "GameStateMachine.h"



GameStateMachine::GameStateMachine()
{
}


GameStateMachine::~GameStateMachine()
{
}

GameState* GameStateMachine::currentState()
{
	return stack.top();
}

void GameStateMachine::pushState(GameState* state)
{
	stack.push(state);
}

void GameStateMachine::popState()
{
	delete stack.top();
	stack.pop();
}

void GameStateMachine::changeState(GameState* state)
{
	popState();
	pushState(state);
}
