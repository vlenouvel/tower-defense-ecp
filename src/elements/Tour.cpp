/*
 * Tour.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "Tour.h"

Tour::Tour(int tPrix, Coordonnees tCoord) : Batiment(tPrix, tCoord) , niveau(1) {
}

void Tour::monterNiveau()
{
	niveau++;
}

Tour::~Tour() {
}

void Tour::dessiner(sf::RenderWindow &pWindow){
	// TO DO
}
