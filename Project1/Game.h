#pragma once

#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include "Ball.h"
#include <string>

//hacer include de todos los archivos

using namespace std;

typedef unsigned int uint;

enum TextureName {BallTexture, BlocksTexure, PaddleTexture, };

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint NUM_TEXTURES = 5;
const uint FRAMERATE = 60; //¿?
const uint tamElem = 60;
const string pathImages = ""; //Path imágenes

const struct TextureAttributes { string fileName; uint nRows; uint nCols;};

TextureAttributes TEXTUREATTRIBUTES[NUM_TEXTURES] =
	{
		{"ball.png",1,1}, {"bricks.png",2,3}, {"",,}, {"",,}, {"",,}
};

class Game
{
	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;	
		// uint winWidth, winHeight; // También podrían estar aquí
			
		//punteros a todos los elementos;

		bool exit = false;
		bool gameover;
		bool win;
		Texture* textures[NUM_TEXTURES];
		Ball* ball;

		public:
			Game();
			~Game();
			void run();
			void render() const;
			void handleEvents();
			void update();
};