#pragma once

#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include "Ball.h"
#include "Paddle.h"
#include "Wall.h"
#include "Block.h"
#include "BlocksMAP.h"
#include <string>
#include "checkML.h"
#include "Timer.h"
#include "GameObject.h"
#include "ArkanoidObject.h"
#include "MovingObject.h"
#include "Reward.h"
#include "BestPlayers.h"
#include "Lives.h"
#include "ArkanoidError.h"
#include "FileFormatError.h"
#include "FileNotFoundError.h"
#include "SDLError.h"

using namespace std;

typedef unsigned int uint;

enum TextureName {BallTexture, BlocksTexure, PaddleTexture };

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint NUM_TEXTURES = 7;
const uint FRAMERATE = 200; //¿?
const uint ELEM_SIZE = 76;
const uint WALL_SIZE = 20;
const uint ObjSize = 20;
const uint levels = 3;
const Vector2D POS_START_BALL = Vector2D(400,300);
const Vector2D POS_START_PADDLE = Vector2D (400,500);
const Vector2D DIR_START_BALL = Vector2D(0.1, 0.1);
const Vector2D DIR_START_PADDLE = Vector2D(0, 0);
const struct TextureAttributes { string fileName; uint nRows; uint nCols; };

#include <list>

class Game
{
	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;	

		bool exit = false;
		bool pause = false;
		int level = 1;
		uint lastTime = 0;
		list<ArkanoidObject*> lista;
		list<ArkanoidObject*>::iterator firstReward;
		Texture* textures[NUM_TEXTURES];
		Ball* ball;
		Paddle* paddle;
		Wall* wallA;
		Wall* wallI;
		Wall* wallD;
		BlocksMAP* blocksMAP;
		Timer* timer;
		BestPlayers* bestplayers;
		Lives* lives;
		string messageerror = "";
		//levels[3] = { "..\\maps\\level1.ark", "..\\maps\\level2.ark", "..\\maps\\level3.ark" };
		string top[3] = { "..\\saves\\best1.ark", "..\\saves\\best2.ark", "..\\saves\\best3.ark" };

		TextureAttributes TEXTUREATTRIBUTES[NUM_TEXTURES] =
		{
			{"../images/ball.png",1,1}, {"../images/bricks.png",2,3}, {"../images/paddle.png",1,1}, {"../images/side.png",1,1}, {"../images/topside.png",1,1},
			{"../images/timer.png", 1, 11},{"../images/rewards.png", 10, 8}
		};

		public:
			Game(int x);
			~Game();
			void run();
			void render() const;
			void handleEvents();
			void moreLives();
			void paddleLonger();
			void paddleShorter();
			void update();
			void reset();
			void createReward(Reward* reward);
			bool rewardCollides(const SDL_Rect & rect, list<ArkanoidObject*>::iterator it);
			bool collides(const SDL_Rect& rect, const Vector2D& vel, Vector2D& collVector);
			void deleteList(list<ArkanoidObject*>::iterator it);
			void saveGame(uint code);
			void DeleteAll();
			void newGame();
			void loadSave();
			string nextLevel();
};