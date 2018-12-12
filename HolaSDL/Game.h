#pragma once

#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include <string>
#include "checkML.h"
#include "Texture.h"
#include "Button.h"
#include "GameStateMachine.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "PauseState.h"
#include "EndState.h"

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
	MainMenuState* menu;
	PlayState* play;
	PauseState* pause;
	EndState* end;
	GameStateMachine* machine;

public:
	Game();
	GameStateMachine * getMachine();
	~Game();
	void run();
	void render() const;
	void update();
	void handleEvents();
};