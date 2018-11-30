#pragma once

#include "checkML.h"
#include "Game.h"


class ArkanoidError: public logic_error
{
public:
	ArkanoidError();
	//logic_error::what
	~ArkanoidError();

protected:
	string message;
};

