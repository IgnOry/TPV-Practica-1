#include "PauseState.h"



PauseState::PauseState(Game* g): GameState(g)
{
	/*stage.push_back(new Button(game, ...));

	stage.push_back(new Button(game, ...));


	stage.push_back(new Button(game, ...));*/

}


PauseState::~PauseState()
{
}

void PauseState::resume(Game* app)
{
	//app->getStateMachine()->popState(); //popstate tambien elimina el estado

}