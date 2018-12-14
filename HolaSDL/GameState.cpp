#include "GameState.h"

GameState::GameState(Game* g)
{
	app = g;
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

void GameState::render()
{
}

bool GameState::handleEvent(SDL_Event e)
{
	bool handled = false;
	auto it = stage.begin();
	while (it != stage.end() && !handled) {
		if ((*it)->handleEvent(e))
			handled = true;
		else
			++it;
	}
	return handled;
}