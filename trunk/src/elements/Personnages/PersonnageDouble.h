/*
 * PersonnageDouble.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef PERSONNAGEDOUBLE_H_
#define PERSONNAGEDOUBLE_H_

#include "../Personnage.h"

class PersonnageDouble: public Personnage{
public:
	PersonnageDouble(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord);
	virtual ~PersonnageDouble();
	void avancer();
	void mourir();
};

#endif /* PERSONNAGEDOUBLE_H_ */
