/*
 * TourAttaque.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "TourAttaque.h"

TourAttaque::TourAttaque(int tPrix, Coordonnees tCoord, int tNiveau) : Tour(tPrix, tCoord, tNiveau) {
	// TODO Auto-generated constructor stub

}

// Fonction générique qui évite de la réécrire dans les tours filles.
void TourAttaque::agir()
{
	sf::Time timeSinceLastAttack = clockFromLastAttack.getElapsedTime();
	if(timeSinceLastAttack > timeBetweenAttacks)
	{
		clockFromLastAttack.restart();
	//	this->attaque(pCibler);
	}
}

void TourAttaque::changerComportementCiblage(void (*fonctionCiblage)())
{
	pCibler = fonctionCiblage;
}


TourAttaque::~TourAttaque() {
	// TODO Auto-generated destructor stub
}

void TourAttaque::dessiner(sf::RenderWindow &pWindow){
	// TO DO
}

void TourAttaque::trouverCibles()
{
	// TO DO, besoin de la liste des ennemis
}
