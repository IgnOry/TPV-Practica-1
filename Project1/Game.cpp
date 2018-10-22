#include "SDL.h" // Windows
#include "SDL_image.h" // Windows

#include <string>
#include "Game.h"

using namespace std;

typedef unsigned int uint;

Game::Game() {
	// We first initialize SDL
	SDL_Init (SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow( "Perro corre con helicoptero", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr) throw "Error loading the SDL window or renderer";
	// We now create the textures

	for (uint i = 0; i < NUM_TEXTURES; i++) {
		
		SDL_Texture* textures[NUM_TEXTURES];
		string filename[] = { "..\\images\\bricks.png" , "..\\images\\ball.png", "..\\images\\paddle.png", "..\\images\\topside.png", "..\\images\\side.png" };

		for (int i = 0; i < NUM_TEXTURES; i++)
		{
			SDL_Surface* surface = IMG_Load(filename[i].c_str());
			textures[i] = SDL_CreateTextureFromSurface(renderer, surface);
			SDL_FreeSurface(surface);
		}
	}
	// We finally create the game objects
	
}
Game::~Game() {
	for( uint i = 0; i < NUM_TEXTURES; i++) delete textures[i];
	SDL_DestroyRenderer (renderer);
	SDL_DestroyWindow( window);
	SDL_Quit();
}

void Game::run()
{
	while (!exit) {
		handleEvents();
		update();
		render();
	}
}

void Game::render() const
{
	SDL_RenderClear(renderer);
	//dog->render();

	SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
	SDL_Event event;
	while
		(SDL_PollEvent(&event) && !exit)
	{
		if (event.type == SDL_QUIT)
			exit = true;

		//dog->handleEvents(event);
	}
}

void Game::update()
{
	//dog->update();
}
