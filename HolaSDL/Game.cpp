#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"

using namespace std;

typedef unsigned int uint;

Game::Game() {

	// We first initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr)
	{
		//throw SDLError(SDL_GetError());
	}

	Texture* txt = new Texture(renderer, "..\images\background1.png", 1, 1);
	//menu = new MainMenuState(this, txt, );
	GameStateMachine singleton = GameStateMachine();

	//MainMenuState menu = new MainMenuState(this, txt, );

	//singleton.changeState();

	/*for (uint i = 0; i < NUM_TEXTURES; i++)
	{
		textures[i] = new Texture(renderer, TEXTUREATTRIBUTES[i].fileName, TEXTUREATTRIBUTES[i].nRows, TEXTUREATTRIBUTES[i].nCols);
		if (textures[i] == nullptr)
			throw SDLError(IMG_GetError());
	}

	/*switch (x)
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
	}*/
}

GameStateMachine* Game::getMachine() {
	return machine;
}

Game::~Game() {
	//for (uint i = 0; i < NUM_TEXTURES; i++) delete textures[i];
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::run()
{
	while (!exit) {
		handleEvents();
		update();
		render();	//PELIGRO: cuando se acaba el juego se llama a render con una lista vacía, porque se borra dentro de update
	}
}

void Game::render() const
{
	SDL_RenderClear(renderer);

	//for (ArkanoidObject* o : lista)
		//o->render();

	SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event) && !exit)
	{
		/*if (event.type == SDL_QUIT)
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
				paddle->handleEvents(event);*
		}*/
	}
}

void Game::update()
{
	/*if (blocksMAP->BlockNum() == 0)	// paso de nivel
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
		for (ArkanoidObject* o : lista)
			o->update();

		if (lista.front()->getRect().y >= WIN_HEIGHT)
			reset();
	}*/
}



/*map<string, Texture*> textures; //por defecto se usa el operator <, para string está definido

textures.insert(pair<string, Texture*>)"ball", new Texture();
textures["ball"] = new Texture();

t1 = textures.at("ball");
t2 = textures["ball"];

struct Score {
	string nick;
	time.t time;
	unit score;
};

struct ScoreKey {
	unit score;
	time.t time;
};

using Scoresmap = map<ScoreKey, Score>;*/