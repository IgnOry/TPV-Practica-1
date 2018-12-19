#include "PauseState.h"
#include "Game.h"


PauseState::PauseState(Game* g): GameState(g) //3 botones, 3 texturas
{
	game = g;

	//nueva partida
	resumeB = new Button(Vector2D(50, 100), 100, 100, g->getTexture(resumeT), g, resume);
	stage.push_back(resumeB);

	//cargar partida
	saveB = new Button(Vector2D(100, 300), 100, 100, g->getTexture(saveT), g, save);
	stage.push_back(saveB);

	//salir
	menuB = new Button(Vector2D(200, 500), 100, 100, g->getTexture(menuT), g, menu);
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
	app->getMachine()->popState();
}

void PauseState::save(Game* app)
{
	cout << "Guardando partida" << endl;
	//app->getMachine()->popState();
}