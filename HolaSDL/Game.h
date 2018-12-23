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
#include "ArkanoidError.h"
#include "FileFormatError.h"
#include "FileNotFoundError.h"
#include "SDLError.h"

using namespace std;

typedef unsigned int uint;

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint NUM_TEXTURES = 13;
const uint FRAMERATE = 200; //¿?
const uint ELEM_SIZE = 76;
const uint WALL_SIZE = 20;
const uint ObjSize = 20;
const uint levels = 3;
const Vector2D POS_START_BALL = Vector2D(400, 300);
const Vector2D POS_START_PADDLE = Vector2D(400, 500);
const Vector2D DIR_START_BALL = Vector2D(0.1, 0.1);
const Vector2D DIR_START_PADDLE = Vector2D(0, 0);
const struct TextureAttributes { string fileName; uint nRows; uint nCols; };

#include <list>
enum text { playT, exitT, loadT, menuT, resumeT, saveT, ballT, bricksT, paddleT, rewardsT, sideT, topSideT, timerT };


class Game
{
private:
	TextureAttributes TEXTUREATTRIBUTES[NUM_TEXTURES] = { //rutas y  filas y columnas de cada textura
		{"../images/NewGame.png",1,1}, {"../images/exit.png",1,1}, {"../images/load.png",1,1} , {"../images/menu.png",1,1}, {"../images/resume.png",1,1}, 
		{"../images/save.png",1,1}, {"../images/ball.png",1,1}, {"../images/bricks.png",2,3}, {"../images/paddle.png",1,1}, {"../images/rewards.png",10,8}, 
		{"../images/side.png",1,1},{ "../images/topside.png",1,1}, {"../images/timer.png" ,1,11} 
	};
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	GameStateMachine* machine;
	bool exitV = false;
	Texture* textures[NUM_TEXTURES];
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
	void moreLives();
	void paddleLonger();
	void paddleShorter();
};