/*
 * GenerateurVague.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "GenerateurVague.h"

GenerateurVague::GenerateurVague(sf::Time timeElapsed) {
	niveau = 1;
	tempsEntreVague = sf::seconds((float)60);
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

