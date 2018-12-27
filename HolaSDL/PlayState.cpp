#include "PlayState.h"
#include "Game.h"
#include "Reward.h" //dependencia circular


PlayState::PlayState(Game* g, uint mode):GameState(g)
{
	game = g;

	//Creamos todos los objetos del juego (escena PlayState)

	if (mode == 0)
		newGame();
	else if (mode == 1)
		loadSave();
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
	lives = new Lives(Vector2D(WIN_WIDTH - (ObjSize * 3 + ObjSize), WIN_HEIGHT - (ObjSize / 2)), ObjSize * 3, ObjSize / 2, game->getTexture(paddleT)); // ojbsize = ancho del muro
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

void PlayState::update()
{
	GameState::update();

	if (blocksMAP->BlockNum() == 0)	// paso de nivel
	{
		PassLevel();
	}
	else {
			for (auto o = stage.begin(); o != stage.end();)
			{
				auto next = o;
				++next;
				(*o)->update();
				o = next;
			}

		if (stage.front()->getRect().y >= WIN_HEIGHT)
			reset();
	}
}

bool PlayState::handleEvent(SDL_Event e)
{
	if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
		cout << "Menu de pausa" << endl;
		app->getMachine()->pushState(new PauseState(app));
		return true;
	}
	else {

		if (e.type == SDL_QUIT) {
			game->exit();
			return true;
		}

		if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
			paddle->handleEvents(e);
			return true;
		}
	}

	return false;
}

void PlayState::moreLives() {
	lives->more();
}

void PlayState::paddleLonger() {
	paddle->longer();
}

void PlayState::paddleShorter() {
	paddle->shorter();
}

void PlayState::PassLevel()
{
	//bestplayers->CompareTimes(timer->time());
	level++;


	lives->reset();
	resetRewards();
	resetObjects();
}

void PlayState::resetRewards() {
		
	for (auto it = firstReward; it != stage.end();)
	{
		delete *it;
		it = stage.erase(it);
	}
	firstReward = stage.end();
}

void PlayState::resetObjects() {
	// Destruye el mapa de 
	stage.pop_back();
	delete blocksMAP;
	blocksMAP = new BlocksMAP(nextLevel(), game->getTexture(bricksT), WIN_WIDTH);
	stage.push_back(blocksMAP);

	// Resetea la pelota, el paddle y el tiempo
	ball->reset(POS_START_BALL, DIR_START_BALL);
	paddle->reset(POS_START_PADDLE, DIR_START_PADDLE);
	timer->reset();
}

void PlayState::deleteList(list<GameObject*>::iterator it)
{
	if (it == firstReward)
		firstReward++;
	delete* it;
	stage.erase(it);
	cout << "borro reward" << endl;
}

void PlayState::reset() {

	resetRewards();

	if (lives->getLives() > 0) {
		lives->less();
		resetObjects();
	}

	else {
		cout << "Gameover" << endl;
		DeleteAll();

		app->getMachine()->pushState(new EndState(app));
	}
}

void PlayState::createReward(Reward* reward) {
	stage.push_back(reward);
	auto itFR = --(stage.end());
	if (firstReward == stage.end())
		firstReward = itFR;
	reward->it = itFR; // igual no va
}
bool PlayState::rewardCollides(const SDL_Rect& rect, list<GameObject*>::iterator it)
{
	if (paddle->collides(rect)) 
		return true;
	else if (rect.y > WIN_HEIGHT)
		deleteList(it);
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

void PlayState::saveGame(uint code) //puntero a ball, paddle y blocksmap
{
	string filename = std::to_string(code);
	ofstream FileData("..\\saves\\" + filename + ".ark");
	FileData << level << endl;

	for (GameObject* o : stage)
	{
		o->saveToFile(FileData);
	}

	FileData.close();
}

void PlayState::DeleteAll() //hacerlo también con listas?
{
	delete ball;
	delete paddle;
	delete wallA;
	delete wallI;
	delete wallD;
	delete timer;
	delete blocksMAP;
	//delete bestplayers;
	delete lives;

	ball = nullptr;
	paddle = nullptr;
	wallA = nullptr;
	wallI = nullptr;
	wallD = nullptr;
	timer = nullptr;
	//bestplayers = nullptr;
	lives = nullptr;

	stage.clear();
}

void PlayState::loadSave()
{
	cout << "Introduce código de la partida";

	uint code;
	cin >> code;

	string filename = std::to_string(code);
	ifstream FileData("..\\saves\\" + filename + ".ark");
	if (!FileData.good())
		throw FileNotFoundError("El archivo ..\\saves\\" + filename + ".ark" + " no se ha encontrado");

	FileData >> level;		// solo se lee el nivel para crear el blocksmap en new game bien
	FileData.close();
	newGame();


	ifstream file("..\\saves\\" + filename + ".ark"); //Con una sola comprobación basta
	file >> level;
	for (GameObject* o : stage)
	{
		o->loadFromFile(file);
		if (o == nullptr)
			throw FileFormatError("Error en la lectura del archivo");
	}

	file.close();

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
