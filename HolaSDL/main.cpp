
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include "Game.h"

using namespace std;

using uint = unsigned int;

int menu()
{
	int x;

	cout << "(0) - Partida normal" << endl;
	cout << "(1) - Cargar partida" << endl;
	cout << "(2) - Mejores jugadores" << endl;

	cin >> x;
	return x;
}

int main(int argc, char* argv[]){
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int x = menu();

	try {
		Game* game = new Game(x);
		game->run();
		delete game;
	}
	catch (exception e)
	{
		cout << e.what();
	}
	return 0;
}