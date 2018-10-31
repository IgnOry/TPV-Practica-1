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
	//Texture* textures[NUM_TEXTURES];


	for (uint i = 0; i < NUM_TEXTURES; i++) {
		
		textures[i] = new Texture(renderer,TEXTUREATTRIBUTES[i].fileName, TEXTUREATTRIBUTES[i].nRows, TEXTUREATTRIBUTES[i].nCols);
	}
	// We finally create the game objects

	ball = new Ball(Vector2D::Vector2D(400, 300), 20, 20, Vector2D::Vector2D(0.2,-0.1),textures[0], this);
	paddle = new Paddle(Vector2D::Vector2D(400, 500), 120, 20, Vector2D::Vector2D(100, 100), textures[2]);
	wallA = new Wall(0, 0, 800, 20, textures[4]);
	wallI = new Wall(0, 0, 20, 600, textures[3]);
	wallD = new Wall(780, 0, 20, 600, textures[3]);
	blocksMAP = new BlocksMAP("..\\maps\\level01.ark", textures[1], ELEM_SIZE);
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

		paddle->handleEvents(event);
	}

	paddle->handleEvents(event);
}

void Game::update()
{
	ball->update();
	paddle->update();
}

bool Game::collides(const SDL_Rect& rect, const Vector2D& vel, Vector2D& collVector)
{
	//caso bloques
	if ((rect.y - rect.h) < blocksMAP->size())
	{
		Block* block = blocksMAP->collides(rect, vel, collVector);
		if (block != nullptr)
		{
			blocksMAP->ballHitsBlock(*block);
			return true;
		}
	}
	

	//casos muros
	if (SDL_HasIntersection(&rect, &wallA->rect()))
	{
		collVector = Vector2D(0, -1);
		return true;
	} else 
	if (SDL_HasIntersection(&rect, &wallI->rect()))
	{
		collVector = Vector2D(1, 0);
		return true;
	} else
	if (SDL_HasIntersection(&rect, &wallD->rect()))
	{
		collVector = Vector2D(-1, 0);
		return true;
	} else
		if(rect.y >= WIN_HEIGHT){				//CASO ABAJO - TESTEO
			collVector = Vector2D(0, 1);		//CASO ABAJO - TESTEO
			return true;						//CASO ABAJO - TESTEO
		}

	//caso paddle
	if (paddle->collides(rect)) {};


	return false;
	
}
