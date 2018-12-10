#include "GameState.h"



GameState::GameState()
{
}


GameState::~GameState()
{
	for (GameObject* o : stage)
		delete o;
}

void GameState::update()
{
	for (GameObject* o : stage)
		o->update();
}

void GameState::handleEvents(SDL_Event e)
{
	for (GameObject* o : stage)
		o->handleEvents(e);
}

void GameState::render()
{
}
