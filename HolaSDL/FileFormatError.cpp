#include "FileFormatError.h"



FileFormatError::FileFormatError(string filename):ArkanoidError()
{
	message =  "El archivo " + filename + " no tiene el formato correcto";
}


FileFormatError::~FileFormatError()
{
}
