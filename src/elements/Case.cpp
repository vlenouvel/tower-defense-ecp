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

Coordonnees Case::getCoordonnees()
{
	return coordonneesCase;
}

void Case::setHeuristique(Case * pCase){
	Coordonnees coord = pCase->getCoordonnees();
	heuristique = (int)fabs(floor((float)coord.getPosX()/40) - floor((float)coordonneesCase.getPosX()/40)) + (int)fabs(floor((float)coord.getPosY()/40) - floor((float)coordonneesCase.getPosY()/40));
}

int Case::getHeuristique()
{
	return heuristique;
}

void Case::setDistanceEntree(int distance)
{
	distanceEntree = distance;
}

int Case::getDistanceEntree()
{
	return distanceEntree;
}

void Case::setParcourue(bool parcourue)
{
	caseParcourue = parcourue;
}

bool Case::isParcourue()
{
	return caseParcourue;
}

void Case::setOccupee(bool occupee)
{
	caseOccupee = occupee;
}

bool Case::isOccupee()
{
	return caseOccupee;
}

Case::~Case() {
	// VIDE
}
