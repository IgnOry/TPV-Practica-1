#pragma once
class BlocksMAP
{
public:
	BlocksMAP();
	~BlocksMAP();
	//Matriz din�mica de punteros a bloques
	void render();
	int numBloques();
	void cargarArchivo();
};

