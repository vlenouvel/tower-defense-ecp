/*
 * PersonnageGenerateur.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef PERSONNAGEGENERATEUR_H_
#define PERSONNAGEGENERATEUR_H_

#include "../Personnage.h"

class PersonnageGenerateur: public Personnage{
public:
	PersonnageGenerateur(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord);
	virtual ~PersonnageGenerateur();
	void agir();
	void avancer();

private:
	int compteurCreation;
};

#endif /* PERSONNAGEGENERATEUR_H_ */
