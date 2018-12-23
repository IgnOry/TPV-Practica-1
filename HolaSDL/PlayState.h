#pragma once
#include "GameState.h"
#include "Ball.h"
#include "Paddle.h"
#include "Wall.h"
#include "Ball.h"
#include "BlocksMAP.h"
#include "Timer.h"
#include "Lives.h"
#include "Reward.h"


class PlayState : public GameState
{
protected:
	int level = 1;		//nivel acutal
	list<GameObject*>::iterator firstReward;	//iterador a la primera reward
	Game* game;
	Ball* ball;
	Paddle* paddle;
	Wall* wallA;
	Wall* wallI;
	Wall* wallD;
	BlocksMAP* blocksMAP;
	Timer* timer;
	//BestPlayers* bestplayers;
	Lives* lives;
public:
	PlayState(Game* g);
	void newGame();
	~PlayState();
	virtual bool handleEvent(SDL_Event e);

	bool collides(const SDL_Rect & rect, const Vector2D & vel, Vector2D & collVector);
	const uint ELEM_SIZE = 76;
	const uint WALL_SIZE = 20;
	const uint ObjSize = 20;
	const uint levels = 3;
	string nextLevel();
	void createReward(Reward * reward);


};