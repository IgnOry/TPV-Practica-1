#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"

using namespace std;

typedef unsigned int uint;

Game::Game() {
	//menú
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
		cout << "¿Que nivel quieres consultar?" << endl;
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
	DeleteAll();
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

	for (ArkanoidObject* o : lista)
		o->render();
	
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
				saveGame();
			else
				paddle->handleEvents(event);
		}
	}
}

void Game::update()
{
	if (blocksMAP->BlockNum() == 0)	// paso de nivel
	{
		bestPlayers(timer->time());
		level++;
		reset();
	}
	else {	// se llama a los updates de todos los objetos de la lista
		for (ArkanoidObject* o : lista)
			o->update();
	}

	if (lista.front()->getRect().y >= WIN_HEIGHT) 
	{
		reset();
	}
}

void Game::reset() {
	// Destruye el mapa de 
	lista.pop_back();
	delete blocksMAP;
	blocksMAP = new BlocksMAP(levels[level], textures[1], WIN_WIDTH);
	lista.push_back(blocksMAP);

	// Resetea la pelota, el paddle y el tiempo
	ball->reset(POS_START_BALL, DIR_START_BALL);
	paddle->reset(POS_START_PADDLE, DIR_START_PADDLE);
	timer->reset();
}

void Game::bestPlayers(uint time)
{
	ifstream FileData(top[level]);

	int topScores[10];		//valor por defecto de los scores: -1

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

bool Game::Random()
{
	uint prob = rand() % 100 + 1;
	if (prob > RewardProb)
		return true;
	else
		return false;
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
			//if (Random)
				//Crear reward
				//Añadir a la lista, meter iterador?
			return true;
		}
	}
	

	//casos muros
	if (SDL_HasIntersection(&rect, &wallA->getRect()))
	{
		collVector = Vector2D(0, -1);
		return true;
	} 
	else if (SDL_HasIntersection(&rect, &wallI->getRect()))
	{
		collVector = Vector2D(1, 0);
		return true;
	} 
	else if (SDL_HasIntersection(&rect, &wallD->getRect()))
	{
		collVector = Vector2D(-1, 0);
		return true;
	} 

	//caso paddle
	if (paddle->collides(rect)) {	// si colisiona

		SDL_Rect cRect = paddle->getRect();

		if (!(((rect.x+rect.w) < cRect.x) && rect.x > (cRect.x + cRect.w))){		//comprueba que colisiona por encima del paddle,
			paddle->ballHitsPaddle(rect, collVector);								//y no por el lado

		return true;
		}
	}										

	return false;
	
}

void Game::saveGame() //puntero a ball, paddle y blocksmap
{
	ofstream FileData("..\\saves\\save.ark");
	FileData << level << endl;

	for (ArkanoidObject* o : lista)
		o->saveToFile(FileData);
	
	FileData.close();

}

void Game::DeleteAll() //hacerlo también con listas?
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

	lista.clear();

}

void Game::newGame()
{
	ball = new Ball(POS_START_BALL, ObjSize, ObjSize, textures[0], DIR_START_BALL, this);
	lista.push_back(ball);
	paddle = new Paddle(POS_START_PADDLE, ObjSize * 6, ObjSize, textures[2],DIR_START_PADDLE);
	lista.push_back(paddle);
	wallA = new Wall(Vector2D(0, 0), WIN_WIDTH, ObjSize, textures[4]);
	lista.push_back(wallA);
	wallI = new Wall(Vector2D(0, 0), ObjSize, WIN_HEIGHT, textures[3]);
	lista.push_back(wallI);
	wallD = new Wall(Vector2D(WIN_WIDTH- ObjSize, 0), ObjSize, WIN_HEIGHT, textures[3]);
	lista.push_back(wallD);
	timer = new Timer(Vector2D(ObjSize, WIN_HEIGHT - ObjSize), ObjSize, ObjSize, textures[5], SDL_GetTicks() / 1000, 0);
	lista.push_back(timer);
	blocksMAP = new BlocksMAP();
	lista.push_back(blocksMAP);

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
	ifstream FileData("..\\saves\\save.ark");
	FileData >> level;		// solo se lee el nivel para crear el blocksmap en new game bien
	FileData.close();
	newGame();

	ifstream file("..\\saves\\save.ark");
	file >> level;
	for (ArkanoidObject* o : lista)
		o->loadFromFile(file);


	file.close();
}
