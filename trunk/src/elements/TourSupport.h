/*
 * TourSupport.h
 *
 *  TowerDefense ECP
 *       
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
