/*
 * Tour.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "Tour.h"

Tour::Tour(int tPrix, Coordonnees tCoord, int tNiveau) : Batiment(tPrix, tCoord) , niveau(tNiveau) {
}

void Tour::monterNiveau()
{
	niveau++;
}

Tour::~Tour() {
}

void Tour::dessiner(){
	// TO DO
}
