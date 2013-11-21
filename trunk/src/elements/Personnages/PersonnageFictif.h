/*
 * PersonnageFictif.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef PERSONNAGEFICTIF_H_
#define PERSONNAGEFICTIF_H_

#include "../Personnage.h"

class PersonnageFictif: public Personnage{
public:
	PersonnageFictif(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord);
	virtual ~PersonnageFictif();
};

#endif /* PERSONNAGEFICTIF_H_ */