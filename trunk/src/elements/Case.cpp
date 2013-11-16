/*
 * Case.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "Case.h"

Case::Case(int abscisse, int ordonnee) : coordonneesCase(abscisse,ordonnee) {
	distanceEntree = 0;
	heuristique = 0;
	caseParcourue = false;
	caseOccupee = false;
}
void Case::setHeuristique(Coordonnees * pSortie){
	heuristique = pSortie->getPosX() + pSortie->getPosY() - coordonneesCase.getPosX() - coordonneesCase.getPosY();
}

Case::~Case() {
	// TODO Auto-generated destructor stub
}
