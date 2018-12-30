#include "PauseState.h"
#include "PlayState.h"
#include "Game.h"



PauseState::PauseState(Game * g): GameState(g)
{
	game = g;

	//nueva partida
	resumeB = new Button(Vector2D(335, 50), 100, 65, g->getTexture(resumeT), g, resume);
	stage.push_back(resumeB);

	//cargar partida
	saveB = new Button(Vector2D(335, 250), 100, 65, g->getTexture(saveT), g, save);
	stage.push_back(saveB);

	//salir
	menuB = new Button(Vector2D(335, 450), 100, 65, g->getTexture(menuT), g, menu);
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

void PauseState::save(Game* app) //falla por llamarse a un metodo que necesita PlayState desde PauseState
{
	cout << "Introduce código de guardado de partida" << endl;	
	
	//PlayState* pState = app->getMachine()->getPlayState();

	uint code;
	cin >> code;
	//pState->saveGame(code);
	cout << "Guardando de partida" << endl;
	//app->getMachine()->popState();
}