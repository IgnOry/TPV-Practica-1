#include "MainMenuState.h"
#include "Game.h"

MainMenuState::MainMenuState(Game* g, Texture* texture1, Texture* texture2, Texture* texture3, CallBackOnClick cb) :GameState(g) //una textura por botón. Podría pasarse como array de texturas (?)
{
	game = g;

	//nueva partida
	newGameB = new Button(100, 100, texture1, Vector2D(50, 50), g, play);
	stage.push_back(newGameB);

	//cargar partida
	loadGameB = new Button(100, 100, texture2, Vector2D(100, 50), g, load);
	stage.push_back(loadGameB);

	//salir
	exitB = new Button(100, 100, texture2, Vector2D(200, 50), g, exit);
	stage.push_back(exitB);
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::play(Game* game) {
	cout << "jugando" << endl;
	//game->getMachine()->pushState(new PlayState());	//faltan argumentos
}

void MainMenuState::load(Game * game)
{
	cout << "cargando" << endl;
	//game->getMachine()->pushState(new PlayState());	//faltan argumentos
}

void MainMenuState::exit(Game * game)
{
	cout << "saliendo" << endl;
	game->exit();
}
