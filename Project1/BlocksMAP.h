#pragma once
class BlocksMAP
{
public:
	BlocksMAP();
	~BlocksMAP();
	//Matriz dinámica de punteros a bloques
	void render();
	int numBloques();
	void cargarArchivo();
};

