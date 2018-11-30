#include "SDLError.h"



SDLError::SDLError():ArkanoidError()
{
	message += IMG_GetError();
	message += SDL_GetError();
	//message = TTF_GetError();
}


SDLError::~SDLError()
{
}
