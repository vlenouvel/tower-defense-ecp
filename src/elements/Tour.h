/*
 * Tour.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef TOUR_H_
#define TOUR_H_

#include "Batiment.h"

class Tour: public Batiment {
public:
	void monterNiveau();
	virtual ~Tour();

protected:
	// Constructeur protected => pas d'instance possible ;)
	Tour(int tPrix, Coordonnees tCoord, int tNiveau);
	int niveau;
};

#endif /* TOUR_H_ */
