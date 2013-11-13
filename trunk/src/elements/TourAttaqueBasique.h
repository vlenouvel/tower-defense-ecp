/*
 * TourAttaqueBasique.h
 *
 *  Created on: 13 nov. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef TOURATTAQUEBASIQUE_H_
#define TOURATTAQUEBASIQUE_H_

#include "TourAttaque.h"

class TourAttaqueBasique: public TourAttaque {
public:
	TourAttaqueBasique(int tPrix, Coordonnees tCoord, int tNiveau);
	virtual ~TourAttaqueBasique();

private:
	void attaque(void (*fonctionCiblage)());
};

#endif /* TOURATTAQUEBASIQUE_H_ */
