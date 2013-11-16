/*
 * Case.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "Case.h"
#include <cmath>
Case::Case(int abscisse, int ordonnee) : coordonneesCase(abscisse,ordonnee) {
	distanceEntree = 0;
	heuristique = 0;
	caseParcourue = false;
	caseOccupee = false;
}
void Case::setHeuristique(Coordonnees * pSortie){
	heuristique = abs((int)floor((float)pSortie->getPosX()/40) - (int)floor((float)coordonneesCase.getPosX()/40)) + abs((int)floor((float)pSortie->getPosY()/40) - (int)floor((float)coordonneesCase.getPosY()/40));
}

Case::~Case() {
	// TODO Auto-generated destructor stub
}
