#include "PlayState.h"

PlayState::PlayState(Game* g):GameState(g)
{
}


PlayState::~PlayState()
{
}

void PlayState::handleEvents(SDL_Event e)
{
	/*if (e.type == SDL_KEYDOWN)
		if (e.key.keysym.sym == SDLK_ESCAPE)
			//app->getStateMachine()->pushState(new PauseState(app));

		else
			*/
}