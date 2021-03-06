#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"

using namespace std;

typedef unsigned int uint;

Game::Game(int x) {
	
		// We first initialize SDL
		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (window == nullptr || renderer == nullptr)
		{
			throw SDLError(SDL_GetError());
		}

		for (uint i = 0; i < NUM_TEXTURES; i++) 
		{
			textures[i] = new Texture(renderer, TEXTUREATTRIBUTES[i].fileName, TEXTUREATTRIBUTES[i].nRows, TEXTUREATTRIBUTES[i].nCols);
			if (textures[i] == nullptr)
				throw SDLError(IMG_GetError());
		}
	
	switch (x)
	{
	case 0:
		newGame();
		break;
	case 1:
		loadSave();
		break;
	case 2:
		bestplayers = new BestPlayers(levels);
		bestplayers->PrintList();

		delete bestplayers;
		bestplayers = nullptr;
		
		newGame(); //paso a partida
		break;
	default:
		throw SDLError("Cierra el programa, vuelve a abrirlo y pulsa 0 o 1 o 2");
		break;
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
		render();	//PELIGRO: cuando se acaba el juego se llama a render con una lista vac�a, porque se borra dentro de update
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
				{
				if (!pause)
				{
					pause = true;
					uint code;
					cin >> code;
					saveGame(code);
					cout << "Vuelve a pulsar S para reanudar la partida";
				}
				else
					pause = false;
				}
			else
				paddle->handleEvents(event);
		}
	}
}

void Game::moreLives() {
	lives->more();
}

void Game::paddleLonger() {
	paddle->longer();
}

void Game::paddleShorter() {
	paddle->shorter();
}

void Game::PassLevel()
{
	bestplayers->CompareTimes(timer->time());
	level++;

	lives->reset();
	resetRewards();
	resetObjects();
}

void Game::resetRewards() {
	// antes de destruir el mapa de bloques hay que destruir las rewards
	//lista.pop_back();
	for (auto it = firstReward; it != lista.end(); ++it) {
		//delete *it;
		it = lista.erase(it);
	}
	firstReward = lista.end();
}

void Game::resetObjects() {
	// Destruye el mapa de 
	lista.pop_back();
	delete blocksMAP;
	blocksMAP = new BlocksMAP(nextLevel(), textures[1], WIN_WIDTH);
	lista.push_back(blocksMAP);

	// Resetea la pelota, el paddle y el tiempo
	ball->reset(POS_START_BALL, DIR_START_BALL);
	paddle->reset(POS_START_PADDLE, DIR_START_PADDLE);
	timer->reset();
}

void Game::deleteList (list<ArkanoidObject*>::iterator it)
{
	if (it == firstReward)
		firstReward++;
	//delete* it;
	lista.erase(it);
	cout << "borro reward" << endl;
}

void Game::update()
{
	if (blocksMAP->BlockNum() == 0)	// paso de nivel
	{
		PassLevel();
	}
	else {
		if (!pause)	// se llama a los updates de todos los objetos de la lista
			for (auto o = lista.begin(); o != lista.end();)
			{
				auto next = o;
				++next;
				(*o)->update();
				o = next;
			}
		/*for (ArkanoidObject* o : lista)
			o->update();*/

		if (lista.front()->getRect().y >= WIN_HEIGHT)
			reset();
	}
}

void Game::reset() {

	resetRewards();

	if (lives->getLives() > 0) {
		lives->less();
		resetObjects();
	}

	else {
		exit = true;
		cout << "Gameover" << endl;
		DeleteAll();
	}
}

void Game::createReward(Reward* reward) {
	lista.push_back(reward);
	auto itFR = --(lista.end());
	if (firstReward == lista.end())
		firstReward = itFR;
	reward->it = itFR; // igual no va
}
bool Game::rewardCollides(const SDL_Rect& rect, list<ArkanoidObject*>::iterator it)
{
	if (paddle->collides(rect)) return true;
	else if (rect.y > WIN_HEIGHT)
		deleteList(it);
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

			uint p = rand() % 5;
			Reward *reward;
			switch (p)
			{
			case 0:
				reward = new Reward1(Vector2D(rect.x, rect.y), ObjSize, ObjSize, textures[6], Vector2D(0, 0.05), this);
				break;
			case 1:
				reward = new Reward2(Vector2D(rect.x, rect.y), ObjSize, ObjSize, textures[6], Vector2D(0, 0.05), this);
				break;
			case 2:
				reward = new Reward3(Vector2D(rect.x, rect.y), ObjSize, ObjSize, textures[6], Vector2D(0, 0.05), this);
				break;
			case 3:
				reward = new Reward3(Vector2D(rect.x, rect.y), ObjSize, ObjSize, textures[6], Vector2D(0, 0.05), this);
				break;
			case 4:
				reward = new Reward4(Vector2D(rect.x, rect.y), ObjSize, ObjSize, textures[6], Vector2D(0, 0.05), this);
				break;
			default:
				return true;
			}
			createReward(reward);
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

void Game::saveGame(uint code) //puntero a ball, paddle y blocksmap
{

	string filename = std::to_string(code);
	ofstream FileData("..\\saves\\" + filename + ".ark");
	FileData << level << endl;

	for (ArkanoidObject* o : lista)
	{
		o->saveToFile(FileData);
	}

	FileData.close();
}

void Game::DeleteAll() //hacerlo tambi�n con listas?
{
	delete ball;
	delete paddle;
	delete wallA;
	delete wallI;
	delete wallD;
	delete timer;
	delete blocksMAP;
	delete bestplayers;
	delete lives;

	ball = nullptr;
	paddle = nullptr;
	wallA = nullptr;
	wallI = nullptr;
	wallD = nullptr;
	timer = nullptr;
	bestplayers = nullptr;
	lives = nullptr;

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
	bestplayers = new BestPlayers(levels);
	//lista.push_back(bestplayers);
	lives = new Lives(Vector2D(WIN_WIDTH - (ObjSize* 3 + ObjSize), WIN_HEIGHT - (ObjSize / 2)), ObjSize * 3, ObjSize / 2, textures[2]); // ojbsize = ancho del muro
	lista.push_back(lives);																							  //objsize * 3 = ancho del minipaddle
	//Enemy* enemy = new Enemy(Vector2D(400,100), ObjSize * 2, ObjSize * 2, textures[7], Vector2D(0,0));
	//lista.push_back(enemy);
	blocksMAP = new BlocksMAP();
	lista.push_back(blocksMAP);
	//iterador
	firstReward = lista.end();

	blocksMAP->loadFile(nextLevel(), textures[1], WIN_WIDTH);
	
}

void Game::loadSave()
{
	cout << "Introduce c�digo de la partida";

	uint code;
	cin >> code;
	
	string filename = std::to_string(code);
	ifstream FileData("..\\saves\\" + filename +  ".ark");
	if (!FileData.good())
		throw FileNotFoundError("El archivo ..\\saves\\" + filename + ".ark" + " no se ha encontrado");

	FileData >> level;		// solo se lee el nivel para crear el blocksmap en new game bien
	FileData.close();
	newGame();

	
	ifstream file("..\\saves\\" + filename +  ".ark"); //Con una sola comprobaci�n basta
	file >> level;
	for (ArkanoidObject* o : lista)
	{
		o->loadFromFile(file);
		if (o == nullptr)
			throw FileFormatError("Error en la lectura del archivo");
	}

	file.close();

}

string Game::nextLevel()
{
	string nextLevelst = "..\\maps\\level" + std::to_string(level) + ".ark";

	ifstream FileData(nextLevelst);
	if (!FileData.good())
		throw FileNotFoundError("El archivo " + nextLevelst + " no se ha encontrado");
	FileData.close();

	return nextLevelst;
}
