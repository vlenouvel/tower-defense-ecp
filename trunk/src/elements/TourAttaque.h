/*
 * TourAttaque.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef TOURATTAQUE_H_
#define TOURATTAQUE_H_

#include "Tour.h"
#include "ComportementCiblage.h"

class TourAttaque: public Tour {
public:
	TourAttaque();
	void attaque();
	void agir();
	virtual ~TourAttaque();

protected:
	ComportementCiblage compCibl;
};

#endif /* TOURATTAQUE_H_ */
