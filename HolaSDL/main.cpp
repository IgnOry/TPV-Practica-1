#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include "Game.h"
//#include <SDL_ttf.h> // Puede variar dependiendo de la instalación

using namespace std;
using uint = unsigned int;


int main(int argc, char* argv[]){
	Game* game = new Game();
	while (true)
	game->run();
	return 0;
}