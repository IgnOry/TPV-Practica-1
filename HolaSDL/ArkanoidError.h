#pragma once

#include "checkML.h"
#include "Game.h"


class ArkanoidError: public logic_error
{
public:
	ArkanoidError();
	~ArkanoidError();

protected:
	string message;
};

