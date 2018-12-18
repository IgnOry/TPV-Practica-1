#include "PauseState.h"
#include "Game.h"


PauseState::PauseState(Game* g, Texture* texture1, Texture* texture2, Texture* texture3, CallBackOnClick* cb): GameState(g) //3 botones, 3 texturas
{
	game = g;

	//nueva partida
	resumeB = new Button(100, 100, texture1, Vector2D(50, 50), g, resume);
	stage.push_back(resumeB);

	//cargar partida
	saveB = new Button(100, 100, texture2, Vector2D(100, 50), g, save);
	stage.push_back(saveB);

	//salir
	menuB = new Button(100, 100, texture2, Vector2D(200, 50), g, menu);
	stage.push_back(menuB);
}


PauseState::~PauseState()
{
}

void PauseState::resume(Game* app)
{
	cout << "Volviendo a la partida" << endl;
	app->getMachine()->popState(); 
}

void PauseState::menu(Game* app)
{
	cout << "Yendo al menu" << endl;
	app->getMachine()->popState();
}

void PauseState::save(Game* app)
{
	cout << "Guardando partida" << endl;
	//app->getMachine()->popState();
}