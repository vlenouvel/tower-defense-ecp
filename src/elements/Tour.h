/*
 * Tour.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef TOUR_H_
#define TOUR_H_

#include "Batiment.h"

class Tour: public Batiment {
public:
	Tour(int tPrix, Coordonnees tCoord);
	void monterNiveau();
	virtual ~Tour();
	void dessiner(sf::RenderWindow &pWindow);

protected:
	int niveau;
};

#endif /* TOUR_H_ */
