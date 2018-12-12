#include "MainMenuState.h"

MainMenuState::MainMenuState(Game* g, Texture* texture, CallBackOnClick cb):GameState(g)
{
	//nueva partida
	game = g;
	
	newGame = new Button(100, 100, texture, Vector2D(50, 50), g, play); //callback de crear partida
	//cargar partida
	//salir
}


MainMenuState::~MainMenuState()
{
}


void MainMenuState::play(Game* game) {
	cout << "jugando";
	game->getMachine()->pushState(new PlayState());
}