#include "EndState.h"
#include "Game.h"


EndState::EndState(Game* g): GameState(g)
{
	game = g;

	menuB = new Button(Vector2D(335, 150), 100, 65, g->getTexture(menuT), g, menu);
	stage.push_back(menuB);

	exitB = new Button(Vector2D(335, 450), 100, 65, g->getTexture(exitT), g, exit);
	stage.push_back(exitB);
}


EndState::~EndState()
{
}

void EndState::menu(Game * game)
{
	cout << "Yendo al menu" << endl;
	game->getMachine()->pushState(new MainMenuState(game));	//faltan argumentos
}

void EndState::exit(Game * game)
{
	cout << "saliendo" << endl;
	game->exit();
}