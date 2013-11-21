/*
 * PersonnageVolant.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef PERSONNAGEVOLANT_H_
#define PERSONNAGEVOLANT_H_

#include "../Personnage.h"

class PersonnageVolant{
public:
	PersonnageVolant(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord);
	virtual ~PersonnageVolant();
};

#endif /* PERSONNAGEVOLANT_H_ */