#pragma once

#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include <string>
#include "checkML.h"

using namespace std;

typedef unsigned int uint;

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;

#include <list>

class Game
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;


public:
	Game(int x);
	~Game();
	void run();
	void render() const;
	void update();
	void handleEvents();
};