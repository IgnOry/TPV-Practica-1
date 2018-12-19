#include "PlayState.h"
#include "Game.h"

PlayState::PlayState(Game* g):GameState(g)
{
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

		if (!(((rect.x + rect.w) < cRect.x) && rect.x > (cRect.x + cRect.w))) {		//comprueba que colisiona por encima del paddle,
			paddle->ballHitsPaddle(rect, collVector);								//y no por el lado

			return true;
		}
	}

	return false;
}