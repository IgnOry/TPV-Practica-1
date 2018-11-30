#pragma once
#include "checkML.h"
#include "ArkanoidError.h"


class FileFormatError: public ArkanoidError
{
public:
	FileFormatError(string filename);
	~FileFormatError();
};

