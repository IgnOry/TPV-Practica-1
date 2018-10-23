#include "SDL.h" // Windows
#include "SDL_image.h" // Windows

#include <string>
#include "Game.h"

using namespace std;

typedef unsigned int uint;

Game::Game() {
	// We first initialize SDL
	SDL_Init (SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow( "Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr) throw "Error loading the SDL window or renderer";
	// We now create the textures
	Texture* textures[NUM_TEXTURES];


	for (uint i = 0; i < NUM_TEXTURES; i++) {
		
		string filename[] = {"../images/bricks.png" , "..\\images\\ball.png", "..\\images\\paddle.png", "..\\images\\topside.png", "..\\images\\side.png" };
		textures[i] = new Texture(renderer,filename[i], TEXTUREATTRIBUTES[i].nRows, TEXTUREATTRIBUTES[i].nCols);
	}
	// We finally create the game objects

	ball = new Ball(Vector2D::Vector2D(400, 300), 10, 10, Vector2D::Vector2D(0,1),textures[1], this);
	paddle = new Paddle(Vector2D::Vector2D(400, 500), 40, 20, Vector2D::Vector2D(100, 100), textures[2]);
	wallA = new Wall(0, 0, 800, 20, textures[3]);
	wallI = new Wall(0, 0, 20, 600, textures[4]);
	wallD = new Wall(780, 0, 20, 600, textures[4]);
	blocksMAP = new BlocksMAP("..\\maps\\level01.ark", textures[0], ELEM_SIZE);
}
Game::~Game() {
	/*for( uint i = 0; i < NUM_TEXTURES; i++) delete textures[i];
	SDL_DestroyRenderer (renderer);
	SDL_DestroyWindow( window);
	SDL_Quit();*/
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
	ball->render();
	paddle->render();
	wallA->render();
	wallI->render();
	wallD->render();
	blocksMAP->render();
	
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
