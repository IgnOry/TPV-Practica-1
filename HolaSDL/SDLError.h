#pragma once
#include "checkML.h"
#include "ArkanoidError.h"


class SDLError: public ArkanoidError
{
public:
	SDLError(string _message);
	~SDLError();
};

