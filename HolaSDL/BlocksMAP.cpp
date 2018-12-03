#include "BlocksMAP.h"
#include "Game.h"
#include <iostream>
#include <fstream>



BlocksMAP::BlocksMAP():ArkanoidObject()
{
}

BlocksMAP::BlocksMAP(string filepath, Texture* textureD, uint ELEM_BLOCK):ArkanoidObject()
{
	loadFile(filepath, textureD, ELEM_BLOCK);
}

BlocksMAP::~BlocksMAP()
{
	for (int r = 0; r < colums; r++)
	{
		for (int c = 0; c < rows; c++)
		{
			delete blocks[r][c];
			//blocks[r][c] = nullptr;
		}
		delete blocks[r];
	}
	delete[] blocks;
	blocks = nullptr;
}

void BlocksMAP::render()
{
	for (int r = 0; r < colums; r++)
	{
		for (int c = 0; c < rows; c++)
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
void BlocksMAP::loadFromFile(ifstream& file) {
	loadBlocks(file);
}

void BlocksMAP::loadBlocks(ifstream& file) {
	numBlocks = 0;

	int colour;
	for (int r = 0; r < colums; r++) {
		for (int c = 0; c < rows; c++) {
			file >> colour;
			if (colour == 0)
				blocks[r][c] = nullptr;
			else
			{
				blocks[r][c] = new Block(Vector2D(BlockSize * c + 20, (BlockSize / 3) * r + 20), BlockSize, BlockSize / 3, colour - 1, c, r, texture); // se suma 20 porque es el ancho del muro
				numBlocks++;
			}
		}
	}
}

void BlocksMAP::loadFile(const string& filePath, Texture* textureD, uint WIN_WIDTH)
{
	ifstream file;
	file.open(filePath);
	if (!file.good())
	{
		throw new FileNotFoundError("El archivo " + filePath + " no se ha encontrado");
	}

	uint x;
	uint y;

	file >> x >> y;

	blocks = new Block**[x];
	for (int i = 0; i < y; i++)
		blocks[i] = new Block*[y];

	BlockSize = ((WIN_WIDTH-WALL_SIZE * 2)/x) / (x*0.1); // para que se adapte a todos los mapas
	colums = x;
	rows = y;
	texture = textureD;
	numBlocks = 0;
	
	int colour;
	for (int r = 0; r < colums; r++) {
		for (int c = 0; c < rows; c++) {
			file >> colour;
			if (colour > 5 || colour < 0)
				throw new FileFormatError("Error en los colores del mapa de bloques del nivel");
			if (colour == 0)
				blocks[r][c] = nullptr;
			else
			{	
				blocks[r][c] = new Block(Vector2D (BlockSize * c + 20,(BlockSize/3) * r + 20), BlockSize, BlockSize/3, colour-1, c, r, textureD); // se suma 20 porque es el ancho del muro
				numBlocks++;			
			}
		}
	}
	file.close();
}
int BlocksMAP::size() {
	return rows * (BlockSize/3);
}

/* Dados el rectángulo y vector de dirección de la pelota, devuelve un puntero al
   bloque con el que ésta colisiona (nullptr si no colisiona con nadie) y el
   vector normal perpendicular a la superficie de colisión.
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
	En caso de no haber bloque en ese punto (incluido el caso de que p esté fuera
	del espacio del mapa) devuelve nullptr.
*/
Block* BlocksMAP::blockAt(const Vector2D& p)
{
	/*int x = (p.getX() - WALL_SIZE) / BlockSize;
	int y = (p.getY() - WALL_SIZE) / (BlockSize/3);

	if (x > MapSizeX || y > MapSizeY)
		return nullptr;
	else
		return blocks[x][y];

	*/for (int i = 0; i < colums; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			Block* block = blocks[i][j];
			if (block != nullptr) {
				if (p.getX() > block->getX() && p.getX() < (block->getX() + block->getW()))
				{
					if (p.getY() > block->getY() && p.getY() < (block->getY() + block->getH()))
						return block;
				}
			}
		}
	}
	return nullptr; //si p está fuera del mapa o no ha encontrado ningún bloque distinto de nullptr devuelve nullptr*/
}

void BlocksMAP::ballHitsBlock(Block& blockToDestroy) {

	//delete blocks[blockToDestroy.colum()][blockToDestroy.row()];
	blocks[blockToDestroy.colum()][blockToDestroy.row()] = nullptr;
	numBlocks--;
}

uint BlocksMAP::MapX()
{
	return rows;
}


uint BlocksMAP::MapY()
{
	return rows;
}

Block*** BlocksMAP::BlockStructure()
{
	return blocks;
}

void BlocksMAP::saveToFile(ofstream& file) {

	for (int i = 0; i < MapX(); i++)
	{
		for (int j = 0; j < MapY(); j++)
		{
			if (blocks[i][j] != nullptr) //acceso a blocksmap
			{
				file << (blocks[i][j]->getColour() + 1) << " ";
			}
			else
			{
				file << 0 << " ";
			}
		}

		file << endl;
	}
}


