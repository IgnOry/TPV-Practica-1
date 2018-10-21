#pragma once

#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include "Dog.h"
#include "Helicopter.h"

#include <string>

using namespace std;

typedef unsigned int uint;

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint NUM_TEXTURES = 5;
const uint FRAMERATE = 60; //¿?
//const uint TAMANO_ELEMENTOS = ¿?

class
	Game
{
	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;	
		// uint winWidth, winHeight; // También podrían estar aquí
			
		//Dog* dog = nullptr;
		//Helicopter* helicopter = nullptr;
		bool exit = false;
		bool gameover;
		bool win;
		Texture* textures[NUM_TEXTURES];


		public:
			Game();
			~Game();
			void run();
			void render() const;
			void handleEvents();
			void update();
};