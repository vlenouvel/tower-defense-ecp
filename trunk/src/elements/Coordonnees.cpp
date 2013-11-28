/*
 * Coordonnees.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "Coordonnees.h"

Coordonnees::Coordonnees(int x,int y) : posX(x), posY(y) {
	// VIDE
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
	// VIDE
}

