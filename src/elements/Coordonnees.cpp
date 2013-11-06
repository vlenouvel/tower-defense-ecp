/*
 * Coordonnees.cpp
 *
 *  Created on: 6 nov. 2013
 *      Author: Vincent Lenouvel
 */

#include "Coordonnees.h"

Coordonnees::Coordonnees(int x,int y) : posX(x), posY(y) {
	// TODO Auto-generated constructor stub

}

int Coordonnees::getPosX()
{
	return posX;
}

int Coordonnees::getPosY()
{
	return posY;
}

void Coordonnees::setPosX(int x)
{
	posX = x;
}

void Coordonnees::setPosY(int y)
{
	posY = y;
}

Coordonnees::~Coordonnees() {
	// TODO Auto-generated destructor stub
}

