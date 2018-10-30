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
const uint ELEM_SIZE = 76;
const string PATH_IMAGES = ""; //Path imágenes

const struct TextureAttributes { string fileName; uint nRows; uint nCols; };


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
		Wall* wallA;
		Wall* wallI;
		Wall* wallD;
		BlocksMAP* blocksMAP;
		
		TextureAttributes TEXTUREATTRIBUTES[NUM_TEXTURES] =
		{
			{"../images/ball.png",1,1}, {"../images/bricks.png",2,3}, {"../images/paddle.png",1,1}, {"../images/side.png",1,1}, {"../images/topside.png",1,1}
		};

		public:
			Game();
			~Game();
			void run();
			void render() const;
			void handleEvents();
			void update();
			bool collides(const SDL_Rect& rect, const Vector2D& vel, Vector2D& collVector);
};