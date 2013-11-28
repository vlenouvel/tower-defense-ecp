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
	Coordonnees getCoordonnees();
	int getHeuristique();
	void setHeuristique(Case * pCase);
	int getDistanceEntree();
	void setDistanceEntree(int distance);
	bool isParcourue();
	void setParcourue(bool parcourue);
	bool isOccupee();
	void setOccupee(bool occupee);

private:
	Coordonnees coordonneesCase;
	int distanceEntree;
	int heuristique;
	bool caseParcourue;
	bool caseOccupee;

};

#endif /* CASE_H_ */
