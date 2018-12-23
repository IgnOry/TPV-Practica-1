#include "PlayState.h"
#include "Game.h"

PlayState::PlayState(Game* g):GameState(g)
{
	//Creamos todos los objetos del juego (escena PlayState)
	newGame();
}

void PlayState::newGame() {
	ball = new Ball(POS_START_BALL, ObjSize, ObjSize, game->getTexture(ballT), DIR_START_BALL, this);
	stage.push_back(ball);
	paddle = new Paddle(POS_START_PADDLE, ObjSize * 6, ObjSize, game->getTexture(paddleT), DIR_START_PADDLE);
	stage.push_back(paddle);
	wallA = new Wall(Vector2D(0, 0), WIN_WIDTH, ObjSize, game->getTexture(topSideT));
	stage.push_back(wallA);
	wallI = new Wall(Vector2D(0, 0), ObjSize, WIN_HEIGHT, game->getTexture(sideT));
	stage.push_back(wallI);
	wallD = new Wall(Vector2D(WIN_WIDTH - ObjSize, 0), ObjSize, WIN_HEIGHT, game->getTexture(sideT));
	stage.push_back(wallD);
	timer = new Timer(Vector2D(ObjSize, WIN_HEIGHT - ObjSize), ObjSize, ObjSize, game->getTexture(timerT), SDL_GetTicks() / 1000, 0);
	stage.push_back(timer);
	//bestplayers = new BestPlayers(levels);
	//lista.push_back(bestplayers);
	lives = new Lives(Vector2D(WIN_WIDTH - (ObjSize * 3 + ObjSize), WIN_HEIGHT - (ObjSize / 2)), ObjSize * 3, ObjSize / 2, game->getTexture(paddleT); // ojbsize = ancho del muro
	stage.push_back(lives);																							  //objsize * 3 = ancho del minipaddle
	//Enemy* enemy = new Enemy(Vector2D(400,100), ObjSize * 2, ObjSize * 2, textures[7], Vector2D(0,0));
	//lista.push_back(enemy);
	blocksMAP = new BlocksMAP();
	stage.push_back(blocksMAP);
	//iterador
	firstReward = stage.end();

	blocksMAP->loadFile(nextLevel(), game->getTexture(bricksT), WIN_WIDTH);

}


PlayState::~PlayState()
{
}

bool PlayState::handleEvent(SDL_Event e)
{
	if (e.type == SDL_KEYDOWN)
		if (e.key.keysym.sym == SDLK_ESCAPE)
		{
			cout << "Menu de pausa" << endl;
			app->getMachine()->pushState(new PauseState(app));

			return true;
		}

	return false;
}

bool PlayState::collides(const SDL_Rect& rect, const Vector2D& vel, Vector2D& collVector)
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
				reward = new Reward1(Vector2D(rect.x, rect.y), ObjSize, ObjSize, game->getTexture(rewardsT), Vector2D(0, 0.05), this);
				break;
			case 1:
				reward = new Reward2(Vector2D(rect.x, rect.y), ObjSize, ObjSize, game->getTexture(rewardsT), Vector2D(0, 0.05), this);
				break;
			case 2:
				reward = new Reward3(Vector2D(rect.x, rect.y), ObjSize, ObjSize, game->getTexture(rewardsT), Vector2D(0, 0.05), this);
				break;
			case 3:
				reward = new Reward3(Vector2D(rect.x, rect.y), ObjSize, ObjSize, game->getTexture(rewardsT), Vector2D(0, 0.05), this);
				break;
			case 4:
				reward = new Reward4(Vector2D(rect.x, rect.y), ObjSize, ObjSize, game->getTexture(rewardsT), Vector2D(0, 0.05), this);
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

		if (!(((rect.x + rect.w) < cRect.x) && rect.x > (cRect.x + cRect.w))) {		//comprueba que colisiona por encima del paddle,
			paddle->ballHitsPaddle(rect, collVector);								//y no por el lado

			return true;
		}
	}

	return false;
}

void PlayState::createReward(Reward* reward) {
	stage.push_back(reward);
	auto itFR = --(stage.end());
	if (firstReward == stage.end())
		firstReward = itFR;
	reward->it = itFR; // igual no va
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

string PlayState::nextLevel()
{
	string nextLevelst = "..\\maps\\level" + std::to_string(level) + ".ark";

	ifstream FileData(nextLevelst);
	if (!FileData.good())
		throw FileNotFoundError("El archivo " + nextLevelst + " no se ha encontrado");
	FileData.close();

	return nextLevelst;
}
