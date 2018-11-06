#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"

using namespace std;

typedef unsigned int uint;

Game::Game(int x) {
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
	
	blocksMAP = new BlocksMAP();


	if (x == 0)
	{
		newGame();
	}

	else if (x == 1)
	{
		loadSave();
	}
	else
		throw new exception ("Cierra el programa, vuelve a abrirlo y pulsa 0 o 1");
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
	timer->render();
	
	SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
	SDL_Event event;
	
	while (SDL_PollEvent(&event) && !exit)
	{
		if (event.type == SDL_QUIT)
			exit = true;
		else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
		{
			if (event.key.keysym.sym == SDLK_s)
				saveGame(ball, paddle, blocksMAP);
			else
				paddle->handleEvents(event);
		}
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
	timer->update();
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
		if (rect.y >= WIN_HEIGHT) {	/*			//CASO ABAJO - TESTEO
			collVector = Vector2D(0, 1);		//CASO ABAJO - TESTEO
			return true;						//CASO ABAJO - TESTEO
			*/

			Destroy();
			newGame();
		}

	//caso paddle
	if (paddle->collides(rect)) {	

		SDL_Rect cRect = paddle->rect();

		if (!(((rect.x+rect.w) < cRect.x) && rect.x > (cRect.x + cRect.w))){
			paddle->ballHitsPaddle(rect, collVector);

		return true;
		}
	}										

	return false;
	
}

void Game::saveGame(Ball* ball, Paddle* paddle, BlocksMAP* blocksmap) //puntero a ball, paddle y blocksmap
{
	ofstream saveFile("..\\saves\\saveMap.ark");

	Block*** blocks = blocksMAP->BlockStructure();

	saveFile << blocksMAP->MapX() << endl;

	saveFile << blocksMAP->MapY() << endl;

	for (int i = 0; i < blocksMAP->MapX(); i++)
	{ 
		for (int j = 0; j < blocksMAP->MapY(); j++)
		{
			if (blocks[i][j] != nullptr) //acceso a blocksmap
			{
				saveFile << (blocks[i][j]->getColour()+1) << " ";
			}
			else
			{
				saveFile << 0 << " ";
			}
		}

		saveFile << endl;
	}

	saveFile.close();

	ofstream FileData("..\\saves\\save.ark");

	FileData << paddle->getPosition().getX() << endl;
	FileData << paddle->getPosition().getY() << endl;

	FileData << paddle->getDirection().getX() << endl;
	FileData << paddle->getDirection().getY() << endl;

	FileData << ball->getPosition().getX() << endl;
	FileData << ball->getPosition().getY() << endl;
	FileData << ball->getDirection().getX() << endl;
	FileData << ball->getDirection().getY() << endl;


	FileData << level << endl;
	//time o rebotes (puntuacion) (?)

	FileData.close();

}

void Game::Destroy()
{
	delete ball;
	delete paddle;
	delete wallA;
	delete wallI;
	delete wallD;
	delete timer;

	blocksMAP->~BlocksMAP();

	ball = nullptr;
	paddle = nullptr;
	wallA = nullptr;
	wallI = nullptr;
	wallD = nullptr;
	timer = nullptr;

}

void Game::newGame()
{
	ball = new Ball(POS_START_BALL, 20, 20, DIR_START_BALL, textures[0], this);
	paddle = new Paddle(POS_START_PADDLE, 120, 20, DIR_START_PADDLE, textures[2]);
	wallA = new Wall(0, 0, WIN_WIDTH, 20, textures[4]);
	wallI = new Wall(0, 0, 20, WIN_HEIGHT, textures[3]);
	wallD = new Wall(WIN_WIDTH-20, 0, 20, WIN_HEIGHT, textures[3]);
	timer = new Timer(textures[5], Vector2D (20,0), 20, 20); //Rellenar

	try {
		blocksMAP->loadFile(levels[level], textures[1], WIN_WIDTH);
	}
	catch (exception e)
	{
		cout << "Error en la carga del mapa";
		std::exit(1);
	}
}

void Game::loadSave()
{
	blocksMAP->loadFile("..\\saves\\saveMap.ark", textures[1], WIN_WIDTH);

	ifstream FileData("..\\saves\\save.ark");

	
	//ver donde deja el punto de lectura de File

	double padPosX;
	double padPosY;
	double padDirX;
	double padDirY;

	double ballPosX;
	double ballPosY;
	double ballDirX;
	double ballDirY;

	FileData >> padPosX;
	FileData >> padPosY;
	Vector2D startPaddle = Vector2D(padPosX, padPosY);
	
	FileData >> padDirX;
	FileData >> padDirY;
	Vector2D dirPaddle = Vector2D(padDirX, padDirY);


	FileData >> ballPosX;
	FileData >> ballPosY;
	Vector2D startBall = Vector2D(ballPosX, ballPosY);

	FileData >> ballDirX;
	FileData >> ballDirY;
	Vector2D dirBall = Vector2D(ballDirX, ballDirY);


	FileData >> level;

	FileData.close();

	ball = new Ball(startBall, 20, 20, dirBall, textures[0], this);
	paddle = new Paddle(startPaddle, 120, 20, dirPaddle, textures[2]);
	wallA = new Wall(0, 0, WIN_WIDTH, 20, textures[4]);
	wallI = new Wall(0, 0, 20, WIN_HEIGHT, textures[3]);
	wallD = new Wall(780, 0, 20, WIN_HEIGHT, textures[3]);
}
