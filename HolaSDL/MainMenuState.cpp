#include "MainMenuState.h"
#include "Game.h"

MainMenuState::MainMenuState(Game* g) :GameState(g)
{
	game = g;

	//nueva partida
	newGameB = new Button(100, 100, g->getTexture(playT), Vector2D(100, 100), g, play);
	stage.push_back(newGameB);

	//cargar partida
	loadGameB = new Button(100, 100, g->getTexture(loadT), Vector2D(100, 300), g, load);
	stage.push_back(loadGameB);

	//salir
	exitB = new Button(100, 100, g->getTexture(exitT), Vector2D(100, 500), g, exit);
	stage.push_back(exitB);
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::play(Game* game) {
	cout << "jugando" << endl;
	game->getMachine()->pushState(new PlayState(game));
}

void MainMenuState::load(Game * game)
{
	cout << "cargando" << endl;
	game->getMachine()->pushState(new PlayState(game));	//faltan argumentos
}

void MainMenuState::exit(Game * game)
{
	cout << "saliendo" << endl;
	game->exit();
}
