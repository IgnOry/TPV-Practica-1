#pragma once

#include "Game.h"
#include <math.h>
class Vector2D
{

private:
	double x; //Posicion X
	double y; //Posicion Y

public:
	Vector2D();
	~Vector2D();
	void darValor(double posX, double posY); //Se implementa por indicacion de Visual Studio de la necesidad de una constructora sin argumentos (No se encontró un constructor predeterminado)
	double consultaX();
	double consultaY();
	void sumaVector(Vector2D sumando);
	void restaVector(Vector2D restando);
	void productoVectorEscalar(uint escalar); //puede que haya que hacer que devuelva Vector2D
	uint productoEscalarVectores(Vector2D producto);
	uint normalizarVector();
	
	//Falta meter los métodos como operador
};
