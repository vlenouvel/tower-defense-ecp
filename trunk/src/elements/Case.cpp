/*
 * Case.cpp
 *
 *  TowerDefense ECP
 *       
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
	heuristique = (int)fabs(floor((float)pSortie->getPosX()/40) - floor((float)coordonneesCase.getPosX()/40)) + (int)fabs(floor((float)pSortie->getPosY()/40) - floor((float)coordonneesCase.getPosY()/40));
}

Case::~Case() {
	// VIDE
}
