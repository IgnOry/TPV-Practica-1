#pragma once

#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include <string>
#include "checkML.h"
#include "Texture.h"
#include "GameStateMachine.h"
#include "GameState.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "PauseState.h"
#include "EndState.h"

using namespace std;

typedef unsigned int uint;

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;

#include <list>
enum text { playT, exitT, loadT, menuT, resumeT, saveT };


class Game
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	GameStateMachine* machine;
	bool exitV = false;
	Texture* textures[6];

public:
	Game();
	GameStateMachine* getMachine();
	~Game();
	void run();
	void render() const;
	void update();
	void exit();
	void handleEvents();
	Texture* getTexture(text name);
};