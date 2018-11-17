#pragma once
#include "checkML.h"

class GameObject
{
public:
	GameObject();
	~GameObject();
	virtual void render();
	virtual void update();
	virtual void handleEvents();
};

