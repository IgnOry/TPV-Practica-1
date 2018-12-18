#include "EndState.h"
#include "Game.h"


EndState::EndState(Game* g): GameState(g)
{
	game = g;
}


EndState::~EndState()
{
}

void EndState::menu(Game * game)
{
	cout << "Yendo al menu" << endl;
	//game->getMachine()->pushState(new PlayState());	//faltan argumentos
}

void EndState::exit(Game * game)
{
	cout << "saliendo" << endl;
	game->exit();
}