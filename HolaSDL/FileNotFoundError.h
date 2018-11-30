#pragma once
#include "checkML.h"
#include "ArkanoidError.h"

class FileNotFoundError: public ArkanoidError
{
public:
	FileNotFoundError();
	~FileNotFoundError();
};

