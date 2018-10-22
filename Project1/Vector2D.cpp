#include "Vector2D.h"
#include "Game.h"
#include <math.h>

Vector2D::Vector2D(double posX, double posY)
{
	double x = posX;
	double y = posY;
}


Vector2D::~Vector2D()
{
}

double Vector2D::consultaX()
{
	return x;
}

double Vector2D::consultaY()
{
	return y;
}

void Vector2D::sumaVector(Vector2D sumando)
{
	x = x + sumando.consultaX();
	y = y + sumando.consultaY();
}

void Vector2D::restaVector(Vector2D restando)
{
	x = x - restando.consultaX();
	y = y - restando.consultaY();
}

void Vector2D::productoVectorEscalar(uint escalar)
{
	x = x * escalar;
	y = y * escalar;
}

uint Vector2D::productoEscalarVectores(Vector2D producto)
{
	uint compX = x * producto.consultaX();
	uint compY = y * producto.consultaY();

	uint n = compX + compY;

	return n;
}

uint Vector2D::normalizarVector()
{
	//elevar al cuadrado cada componente
	uint compX = x * x;
	uint compY = y * y;

	//Raíz cuadrada
	uint n = sqrt((compX + compY));

	return n;
	
}


