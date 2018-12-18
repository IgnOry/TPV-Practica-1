

#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include "Game.h"
//#include <SDL_ttf.h> // Puede variar dependiendo de la instalación

using namespace std;
using uint = unsigned int;

int main(int argc, char* argv[]) {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	/*cout << "Hello World" << endl;
	cout << "Hello World" << endl;
	int a;
	cin >> a;*/
	try {
		Game game;
		game.run();
	}
	catch (exception e)
	{
		cout << e.what();
	}
	return 0;
}