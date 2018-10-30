#include "BlocksMAP.h"
#include <iostream>
#include <fstream>



BlocksMAP::BlocksMAP()
{
}

BlocksMAP::BlocksMAP(string filepath, Texture* textureD, uint ELEM_BLOCK)
{
	loadFile(filepath, textureD, ELEM_BLOCK);
}

BlocksMAP::~BlocksMAP()
{
}

void BlocksMAP::render()
{
	uint rows = MapSizeX;
	uint columns = MapSizeY;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			if (blocks[r][c] != nullptr)
			blocks[r][c]->render();
		}
	}
}

uint BlocksMAP::BlockNum()
{
	return numBlocks;
}

void BlocksMAP::loadFile(const string& filePath, Texture* textureD, uint ELEM_BLOCK)
{
	ifstream file;
	file.open(filePath);

	int x;
	int y;

	file >> x >> y;

	blocks = new Block**[x];
	for (int i = 0; i < y; i++)
		blocks[i] = new Block*[y];

	BlockSize = ELEM_BLOCK;
	MapSizeX = x;
	MapSizeY = y;
	texture = textureD;
	
	int colour;
	for (int r = 0; r < x; r++) {
		for (int c = 0; c < y; c++) {
			file >> colour;
			if (colour == 0)
				blocks[r][c] = nullptr;
			else
			{
				blocks[r][c] = new Block(BlockSize,(BlockSize/3), BlockSize, BlockSize/3, colour, c, r, textureD);
				numBlocks++;
			}
		}
	}
}
int BlocksMAP::size() {
	return MapSizeY * (BlockSize/3);
}

/* Dados el rect�ngulo y vector de direcci�n de la pelota, devuelve un puntero al
   bloque con el que �sta colisiona (nullptr si no colisiona con nadie) y el
   vector normal perpendicular a la superficie de colisi�n.
*/
Block* BlocksMAP::collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector) {

	Vector2D p0 = { double(ballRect.x),  double(ballRect.y) }; // top-left
	Vector2D p1 = { double(ballRect.x + ballRect.w),  double(ballRect.y) }; // top-right
	Vector2D p2 = { double(ballRect.x),  double(ballRect.y + ballRect.h) }; // bottom-left
	Vector2D p3 = { double(ballRect.x + ballRect.w),  double(ballRect.y + ballRect.h) }; // bottom-right
	Block* b = nullptr;

	if (ballVel.getX() < 0 && ballVel.getY() < 0)
	{
		if ((b = blockAt(p0)))
		{
			if ((b->getY() + b->getH() - p0.getY()) <= (b->getX() + b->getW() - p0.getX()))
				collVector = { 0,1 }; // Borde inferior mas cerca de p0
			else
				collVector = { 1,0 }; // Borde dcho mas cerca de p0
		}
		else if ((b = blockAt(p1))) {
			collVector = { 0,1 };
		}
		else if ((b = blockAt(p2))) collVector = { 1,0 };
	}

	else if (ballVel.getX() >= 0 && ballVel.getY() < 0) {
		if ((b = blockAt(p1))) {
			if (((b->getY() + b->getH() - p1.getY()) <= (p1.getX() - b->getX())) || ballVel.getX() == 0)
				collVector = { 0,1 }; // Borde inferior mas cerca de p1
			else
				collVector = { -1,0 }; // Borde izqdo mas cerca de p1
		}
		else if ((b = blockAt(p0))) {
			collVector = { 0,1 };
		}
		else if ((b = blockAt(p3))) collVector = { -1,0 };
	}
	else if (ballVel.getX() > 0 && ballVel.getY() > 0) {
		if ((b = blockAt(p3))) {
			if (((p3.getY() - b->getY()) <= (p3.getX() - b->getX()))) // || ballVel.getX() == 0)
				collVector = { 0,-1 }; // Borde superior mas cerca de p3
			else
				collVector = { -1,0 }; // Borde dcho mas cerca de p3
		}
		else if ((b = blockAt(p2))) {
			collVector = { 0,-1 };
		}
		else if ((b = blockAt(p1))) collVector = { -1,0 };
	}
	else if (ballVel.getX() < 0 && ballVel.getY() > 0) {
		if ((b = blockAt(p2))) {
			if (((p2.getY() - b->getY()) <= (b->getX() + b->getW() - p2.getX()))) // || ballVel.getX() == 0)
				collVector = { 0,-1 }; // Borde superior mas cerca de p2
			else
				collVector = { 1,0 }; // Borde dcho mas cerca de p0
		}
		else if ((b = blockAt(p3))) {
			collVector = { 0,-1 };
		}
		else if ((b = blockAt(p0))) collVector = { 1,0 };
	}
	return b;
}


/*  Devuelve el puntero al bloque del mapa de bloques al que pertenece el punto p.
	En caso de no haber bloque en ese punto (incluido el caso de que p est� fuera
	del espacio del mapa) devuelve nullptr.
*/
Block* BlocksMAP::blockAt(const Vector2D& p) {
	return nullptr;
}
