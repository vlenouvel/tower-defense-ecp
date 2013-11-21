/*
 * PersonnageBasique.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef PERSONNAGEBASIQUE_H_
#define PERSONNAGEBASIQUE_H_

#include "../Personnage.h"

class PersonnageBasique: public Personnage{
public:
	PersonnageBasique(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord);
	virtual ~PersonnageBasique();
};

#endif /* PERSONNAGEBASIQUE_H_ */