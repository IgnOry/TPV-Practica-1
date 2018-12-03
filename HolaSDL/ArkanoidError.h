#pragma once

#include "checkML.h"
#include <stdexcept>
using namespace std;


class ArkanoidError: public logic_error
{
	protected:
		ArkanoidError(string _message) :logic_error(_message)
		{};
		~ArkanoidError();

	public:
		string what();
};

