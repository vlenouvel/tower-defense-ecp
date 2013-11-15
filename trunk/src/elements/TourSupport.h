/*
 * TourSupport.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef TOURSUPPORT_H_
#define TOURSUPPORT_H_

#include "Tour.h"

class TourSupport : public Tour {
public:
	TourSupport(int tPrix, Coordonnees tCoord);
	virtual ~TourSupport();
	void dessiner(sf::RenderWindow &pWindow);
};

#endif /* TOURSUPPORT_H_ */
