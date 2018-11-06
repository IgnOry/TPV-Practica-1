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

using namespace std;

typedef unsigned int uint;

enum TextureName {BallTexture, BlocksTexure, PaddleTexture };

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint NUM_TEXTURES = 6;
const uint FRAMERATE = 144; //�?
const uint ELEM_SIZE = 76;
const Vector2D POS_START_BALL = Vector2D(400,300);
const Vector2D POS_START_PADDLE = Vector2D (400,500);
const Vector2D DIR_START_BALL = Vector2D(0.25, 0.25);
const Vector2D DIR_START_PADDLE = Vector2D(0, 0);
const struct TextureAttributes { string fileName; uint nRows; uint nCols; };


class Game
{
	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;	
		// uint winWidth, winHeight; // Tambi�n podr�an estar aqu�

		bool exit = false;
		bool gameover;
		bool win;
		int hits;
		int level = 0;
		uint lastTime = 0;
		Texture* textures[NUM_TEXTURES];
		Ball* ball;
		Paddle* paddle;
		Wall* wallA;
		Wall* wallI;
		Wall* wallD;
		BlocksMAP* blocksMAP;
		Timer* timer;
		string levels[3] = { "..\\maps\\level01.ark", "..\\maps\\level02.ark", "..\\maps\\level03.ark" };
		
		TextureAttributes TEXTUREATTRIBUTES[NUM_TEXTURES] =
		{
			{"../images/ball.png",1,1}, {"../images/bricks.png",2,3}, {"../images/paddle.png",1,1}, {"../images/side.png",1,1}, {"../images/topside.png",1,1}, {"../images/timer.png", 1, 10}
		};

		public:
			Game(int x);
			~Game();
			void run();
			void render() const;
			void handleEvents();
			void update();
			bool collides(const SDL_Rect& rect, const Vector2D& vel, Vector2D& collVector);
			void saveGame(Ball * ball, Paddle * paddle, BlocksMAP * blocksmap);
			void Destroy();
			void newGame();
			void loadSave();
};