/*
 * Case.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef CASE_H_
#define CASE_H_

#include "Coordonnees.h"

class Case{
public:
	Case(int abscisse, int ordonnee);
	virtual ~Case();
	Coordonnees coordonneesCase;
	int distanceEntree;
	int heuristique;
	bool caseParcourue;
	bool caseOccupee;
	void setHeuristique(Coordonnees * pSortie);
};

#endif /* CASE_H_ */
