/*
 * Mur.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef MUR_H_
#define MUR_H_

#include "Batiment.h"

class Mur: public Batiment {
public:
	Mur(int tPrix, Coordonnees tCoord);
	virtual ~Mur();
	void dessiner();
};

#endif /* MUR_H_ */
