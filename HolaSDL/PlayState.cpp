#include "PlayState.h"
#include "Game.h"

PlayState::PlayState(Game* g):GameState(g)
{
}


PlayState::~PlayState()
{
}

bool PlayState::handleEvent(SDL_Event e)
{
	if (e.type == SDL_KEYDOWN)
		if (e.key.keysym.sym == SDLK_ESCAPE)
		{
			cout << "Menu de pausa" << endl;
			app->getMachine()->pushState(new PauseState(app));

			return true;
		}

	return false;
}