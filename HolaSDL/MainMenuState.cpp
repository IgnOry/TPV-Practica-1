#include "MainMenuState.h"

MainMenuState::MainMenuState(Game* g, Texture* texture) :GameState(g)
{
	//nueva partida

	newGame = new Button(100, 100, texture, Vector2D(50, 50), g); //callback de crear partida
	//cargar partida
	//salir
}

void MainMenuState::NewGame() {
	app->			//se llama al método de la máquina de estados que devuelve el estado playsate
}


MainMenuState::~MainMenuState()
{
}