/*
 * TourAttaque.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "TourAttaque.h"

TourAttaque::TourAttaque() {
	// TODO Auto-generated constructor stub

}

// Fonction g�n�rique qui �vite de la r��crire dans les tours filles.
void TourAttaque::agir()
{
	sf::Time timeSinceLastAttack = clockFromLastAttack.getElapsedTime();
	if(timeSinceLastAttack > timeBetweenAttacks)
	{
		clockFromLastAttack.restart();
		this->attaque();
	}
}


TourAttaque::~TourAttaque() {
	// TODO Auto-generated destructor stub
}

