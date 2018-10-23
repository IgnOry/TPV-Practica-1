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

using namespace std;

typedef unsigned int uint;

enum TextureName {BallTexture, BlocksTexure, PaddleTexture };

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint NUM_TEXTURES = 5;
const uint FRAMERATE = 60; //¿?
const uint ELEM_SIZE = 60;
const string PATH_IMAGES = ""; //Path imágenes

const struct TextureAttributes { string fileName; uint nRows; uint nCols;};

TextureAttributes TEXTUREATTRIBUTES[NUM_TEXTURES] =
{
	{"ball.png",1,1}, {"bricks.png",2,3}, {"paddle",1,1}, {"side",1,1}, {"topside",1,1}
};

class Game
{
	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;	
		// uint winWidth, winHeight; // También podrían estar aquí

		bool exit = false;
		bool gameover;
		bool win;
		Texture* textures[NUM_TEXTURES];
		Ball* ball;
		Paddle* paddle;
		Wall* wall;
		BlocksMAP* blocksMAP;
		//punteros a todos los elementos;

		public:
			Game();
			~Game();
			void run();
			void render() const;
			void handleEvents();
			void update();
};