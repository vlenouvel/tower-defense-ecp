/*
 * Tour.cpp
 *
 *  TowerDefense ECP
 *       
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
