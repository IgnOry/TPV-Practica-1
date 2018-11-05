#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"

using namespace std;

typedef unsigned int uint;

Game::Game() {
	try {
		// We first initialize SDL
		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (window == nullptr || renderer == nullptr) throw "Error loading the SDL window or renderer";
		// We now create the textures
	}

	catch (exception e)
	{
		cout << "Error en la carga de SDL";
		std::exit(1);
	}
	try {
		for (uint i = 0; i < NUM_TEXTURES; i++) {

			textures[i] = new Texture(renderer, TEXTUREATTRIBUTES[i].fileName, TEXTUREATTRIBUTES[i].nRows, TEXTUREATTRIBUTES[i].nCols);
		}
	}

	catch (exception e)
	{
		cout << "Error en la carga de texturas";
		std::exit(1);

	}
	// Esto de abajo se puede sacar a un método aparte para facilitar la creación de un juego nuevo o la carga de una partida

	ball = new Ball(POS_START_BALL, 20, 20, DIR_START_BALL,textures[0], this);
	paddle = new Paddle(POS_START_PADDLE, 120, 20, DIR_START_PADDLE, textures[2]);
	wallA = new Wall(0, 0, WIN_WIDTH, 20, textures[4]);
	wallI = new Wall(0, 0, 20, WIN_HEIGHT, textures[3]);
	wallD = new Wall(780, 0, 20, WIN_HEIGHT, textures[3]);
	try {
		blocksMAP = new BlocksMAP(levels[level], textures[1], WIN_WIDTH);
	}
	catch (exception e)
	{
		cout << "Error en la carga del mapa";
		std::exit(1);
	}
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
	
	while (SDL_PollEvent(&event) && !exit)
	{
		if (event.type == SDL_QUIT)
			exit = true;
		else if(event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
			paddle->handleEvents(event);
	}
}

void Game::update()
{
	if (blocksMAP->BlockNum() == 0)
	{
		blocksMAP->~BlocksMAP();
		level++;
		blocksMAP = new BlocksMAP(levels[level], textures[1], WIN_WIDTH);
	}
		
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
	} 
	
	else
		if (rect.y >= WIN_HEIGHT) {				//CASO ABAJO - TESTEO
			/*collVector = Vector2D(0, 1);		//CASO ABAJO - TESTEO
			return true;						//CASO ABAJO - TESTEO
		}*/

			lives--;
			//reset nivel (?) Destruir blocksmap, cargarlo de nuevo y devolver ball y paddle a su posicion original

		}

	//caso paddle pelota
	if (paddle->collides(rect)) {	

		SDL_Rect cRect = paddle->rect();

		if (rect.y < (cRect.y + cRect.h))
			paddle->ballHitsPaddle(rect, cRect, collVector);
			//collVector = Vector2D(0, 1);

		return true;
	};											

	return false;
	
}

void Game::saveGame(Ball* ball, Paddle* paddle, BlocksMAP* blocksmap) //puntero a ball, paddle y blocksmap
{
	ofstream saveFile("save.ark");

	for (int i = 0; i < blocksMAP->MapX; i++) //metodos para obtener la X y la Y
	{ 
		for (int j = 0; j < blocksMAP->MapY; j++)
		{
			if (true) //acceso a blocksmap
			{
				//fs << blocks* [i][j].getColour;
			}
			else
			{
				saveFile << 0;
			}
		}

		saveFile << endl;
	}

	saveFile << paddle->getPosition() << endl;
	saveFile << paddle->getDirection() << endl;

	saveFile << ball->getPosition() << endl;
	saveFile << ball->getDirection() << endl;

	saveFile << level << endl;
	saveFile << lives << endl;

	//time o rebotes (puntuacion) (?)

	saveFile.close();

}

/*void Game::loadSave()
{
	ifstream loadFile;

	loadFile >> x;
	mismo orden que save file
}*/
