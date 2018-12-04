#include "Enemy.h"
#include "Texture.h"


Enemy::Enemy(Vector2D pos, uint wid, uint heightD, Texture * ptr, Vector2D direction):MovingObject(pos, wid, heightD, ptr, direction)
{
}

Enemy::~Enemy()
{
}

void Enemy::update()
{
	float x = (rand() % 10 - 4.5);
	float y = (rand() % 10 - 4.5);
	dirPos = dirPos - (Vector2D(x,y) *(dirPos * Vector2D(x,y)) * 2);
	//cout << x << " " << y << endl;
	MovingObject::update();
}

void Enemy::render()
{
	if (frame >= 250* 5) frame = 0;
	ptrTexture->renderFrame(getRect(), ((frame / 250) % 5), ((frame / 50) % 5));
	frame++;
	//cout << getRect().x << getRect().y << endl;
}
