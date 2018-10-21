#pragma once
class Vector2D
{

private:
	double x; //Posicion X
	double y; //Posicion Y

public:
	Vector2D(double posX, double posY);
	~Vector2D();
	double consultaX();
	double consultaY();
	//Normalizarvector
	//SumaVector -Operador
	//RestaVector -Operador
	//ProductoEscalarVector -Operador
	//ProductoVectorEscalar -Operador
};
