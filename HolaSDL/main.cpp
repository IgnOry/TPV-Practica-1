
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include "Game.h"

using namespace std;

using uint = unsigned int;

int menu()
{
	cout << "Menu en progreso" << endl;
	cout << "Pulsa 0 para jugar de forma normal, 1 para cargar una partida guardada" << endl;

	int x;

	cin >> x;
	return x;
}

int main(int argc, char* argv[]){
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//int x = menu();
	try {
		Game* game = new Game(0);
		game->run();
	}
	catch (exception e)
	{
		cout << e.what();
	}
	return 0;
}