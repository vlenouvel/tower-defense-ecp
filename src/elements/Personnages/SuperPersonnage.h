/*
 * SuperPersonnage.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef SUPERPERSONNAGE_H_
#define SUPERPERSONNAGE_H_

#include "../Personnage.h"

class SuperPersonnage: public Personnage{
public:
	SuperPersonnage(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord);
	virtual ~SuperPersonnage();
	void avancer();
private:
	int vieDebut;
};

#endif /* SUPERPERSONNAGE_H_ */
