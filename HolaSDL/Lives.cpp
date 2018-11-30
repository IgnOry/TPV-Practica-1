#include "Lives.h"



Lives::Lives(): ArkanoidObject()
{
	lives = 3;
}


Lives::~Lives()
{
}

uint Lives::current()
{
	return lives;
}

void Lives::less()
{
	lives--;
}
