#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"

using namespace std;

typedef unsigned int uint;

Game::Game() {
	
	int x;

	cout << "(0) - Partida normal" << endl;
	cout << "(1) - Cargar partida" << endl;
	cout << "(2) - Mejores jugadores" << endl;

	cin >> x;

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
	
	if (x == 0)
	{
		newGame();
	}

	else if (x == 1)
	{
		loadSave();
	}

	else if (x == 2)
	{
		cout << "¿Qué nivel quieres consultar?" << endl;
		cin >> x;

		ifstream FileData(top[x]);

		int topScores[10];

		for (int i = 0; i < 10; i++)
		{
			cin >> topScores[i];
		}

		for (int i = 0; i < 10; i++)
		{
			cout << i << ". " << topScores[i] << endl;
		}

		FileData.close();
	}
	else
		throw new exception ("Cierra el programa, vuelve a abrirlo y pulsa 0 o 1 o 2");
}

Game::~Game() {
	for( uint i = 0; i < NUM_TEXTURES; i++) delete textures[i];
	Destroy();
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
		bestPlayers(timer->time());
		level++;
		blocksMAP = new BlocksMAP(levels[level], textures[1], WIN_WIDTH);
	}
		
	ball->update();
	paddle->update();
	timer->update();
}

void Game::bestPlayers(uint time)
{
	ifstream FileData(top[level]);

	int topScores[10];

	for (int i = 0; i < 10; i++)
	{
		cin >> topScores[i];
	}

	if (topScores[9] > 0)
	{
		int i = 0;

		while (topScores[i] < time)
			i++;

		topScores[i] = time;
	}

	else
	{
		int i = 0;

		while (topScores[i] < 0)
			i++;

		topScores[i] = time;
	}
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
	FileData << timer->time() << endl;
	FileData << timer->timeFromDeath() << endl;
	FileData << SDL_GetTicks() / 1000;

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
	delete blocksMAP;

	ball = nullptr;
	paddle = nullptr;
	wallA = nullptr;
	wallI = nullptr;
	wallD = nullptr;
	timer = nullptr;

}

void Game::newGame()
{
	int ObjSize = 20;
	ball = new Ball(POS_START_BALL, ObjSize, ObjSize, DIR_START_BALL, textures[0], this);
	paddle = new Paddle(POS_START_PADDLE, ObjSize * 6, ObjSize, DIR_START_PADDLE, textures[2]);
	wallA = new Wall(0, 0, WIN_WIDTH, ObjSize, textures[4]);
	wallI = new Wall(0, 0, ObjSize, WIN_HEIGHT, textures[3]);
	wallD = new Wall(WIN_WIDTH- ObjSize, 0, ObjSize, WIN_HEIGHT, textures[3]);
	timer = new Timer(textures[5], Vector2D (ObjSize,WIN_HEIGHT - ObjSize), ObjSize, ObjSize, 0, SDL_GetTicks()/1000,  0);
	blocksMAP = new BlocksMAP();

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
	blocksMAP = new BlocksMAP();
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

	uint time;
	int timeFromDeath;
	int ticks;

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
	FileData >> time;
	FileData >> timeFromDeath;
	FileData >> ticks;


	FileData.close();

	ball = new Ball(startBall, 20, 20, dirBall, textures[0], this);
	paddle = new Paddle(startPaddle, 120, 20, dirPaddle, textures[2]);
	wallA = new Wall(0, 0, WIN_WIDTH, 20, textures[4]);
	wallI = new Wall(0, 0, 20, WIN_HEIGHT, textures[3]);
	wallD = new Wall(780, 0, 20, WIN_HEIGHT, textures[3]);
	timer = new Timer(textures[5], Vector2D(20, 580), 20, 20, time, timeFromDeath, ticks); 
}
