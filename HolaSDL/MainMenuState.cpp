#include "MainMenuState.h"
#include "Game.h"

MainMenuState::MainMenuState(Game* g) :GameState(g)
{
	game = g;

	//nueva partida
	newGameB = new Button(Vector2D(335, 50), 100, 65, g->getTexture(playT), g, play);
	stage.push_back(newGameB);

	//cargar partida
	loadGameB = new Button(Vector2D(335, 250), 100, 65, g->getTexture(loadT), g, load);
	stage.push_back(loadGameB);

	//salir
	exitB = new Button(Vector2D(335, 450), 100, 65, g->getTexture(exitT),  g, exit);
	stage.push_back(exitB);
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::play(Game* game) {
	cout << "jugando" << endl;
	game->getMachine()->pushState(new PlayState(game, 0));	

	//game->getMachine()->setPlayState(new PlayState(game,0));
}

void MainMenuState::load(Game * game)
{
	cout << "cargando" << endl;
	game->getMachine()->pushState(new PlayState(game,1));
}

void MainMenuState::exit(Game * game)
{
	cout << "saliendo" << endl;
	game->exit();
}
