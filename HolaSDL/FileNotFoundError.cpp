#include "FileNotFoundError.h"



FileNotFoundError::FileNotFoundError(string filename):ArkanoidError()
{
	message = "No se ha podido encontrar el archivo" + filename;
}


FileNotFoundError::~FileNotFoundError()
{
}
