#pragma once
#include "checkML.h"

class GameObject
{
public:
	GameObject();
	~GameObject();
	void render();
	void update();
	void handleEvents();
};

