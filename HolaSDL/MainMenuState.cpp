#include "MainMenuState.h"

MainMenuState::MainMenuState(Game* g, Texture* texture, CallBackOnClick cb):GameState(g)
{
	//nueva partida

	newGame = new Button(100, 100, texture, Vector2D(50, 50), g, cb); //callback de crear partida
	//cargar partida
	//salir
}


MainMenuState::~MainMenuState()
{
}
