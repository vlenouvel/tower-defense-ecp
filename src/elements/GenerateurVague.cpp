/*
 * GenerateurVague.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "GenerateurVague.h"
GenerateurVague::GenerateurVague(sf::Time timeElapsed) {
	niveau = 1;

	// definition du temps d'attente entre deux vagues
	tempsEntreVague = sf::seconds((float)10);
	tempsDerniereVague = timeElapsed - tempsEntreVague;
}

void GenerateurVague::genererVague(sf::Time timeElapsed)
{
	if(timeElapsed - tempsDerniereVague >= tempsEntreVague) {
		Vague vague(niveau);
		tempsDerniereVague = timeElapsed;
		vague.agir();
		niveau++;
	}
}

GenerateurVague::~GenerateurVague() {
	// TODO Auto-generated destructor stub
}

