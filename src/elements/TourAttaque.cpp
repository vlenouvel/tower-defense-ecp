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

// Fonction générique qui évite de la réécrire dans les tours filles.
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

