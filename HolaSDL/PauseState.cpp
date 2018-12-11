#include "PauseState.h"



PauseState::PauseState()
{
	/*stage.push_back(new Button(game, ...));

	stage.push_back(new Button(game, ...));


	stage.push_back(new Button(game, ...));*/

}


PauseState::~PauseState()
{
}

static void resume() //puede llamarse al juego para desapilar el estado
{
	//app->getStateMachine()->popState(); //popstate tambien elimina el estado
}
