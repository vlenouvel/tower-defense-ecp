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
	Tour(Coordonnees tCoord);
	virtual void monterNiveau();
	virtual ~Tour();
	void dessiner(sf::RenderWindow &pWindow);
	bool verifierAmelioration();
	int getNiveau();

protected:
	int niveau;
	sf::Sound sonCreationTour;
};

#endif /* TOUR_H_ */
