#pragma once
#include "GameState.h"
#include "Ball.h"
#include "Paddle.h"
#include "Wall.h"
#include "Block.h"
#include "BlocksMAP.h"
#include "Timer.h"
#include "Lives.h"
#include "Reward.h"


class PlayState : public GameState
{
public:
	PlayState(Game* g);
	~PlayState();
	virtual bool handleEvent(SDL_Event e);

	bool collides(const SDL_Rect & rect, const Vector2D & vel, Vector2D & collVector);

protected:
	Ball* ball;
	Paddle* paddle;
	Wall* wallA;
	Wall* wallI;
	Wall* wallD;
	BlocksMAP* blocksMAP;
	Timer* timer;
	//BestPlayers* bestplayers;
	Lives* lives;
};