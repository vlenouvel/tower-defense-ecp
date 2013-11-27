/*
 * PersonnageAccelerant.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef PERSONNAGEACCELERANT_H_
#define PERSONNAGEACCELERANT_H_

#include "../Personnage.h"

class PersonnageAccelerant: public Personnage{
public:
	PersonnageAccelerant(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord);
	virtual ~PersonnageAccelerant();
	void avancer();

private:
	int vieDebut;
	int vitesseDebut;
};

#endif /* PERSONNAGEACCELERANT_H_ */
