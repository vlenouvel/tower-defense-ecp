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
	virtual bool isTourAttaque();
	virtual int getDommages();
	virtual void vendreTour();

protected:
	int niveau;
	sf::Sound sonCreationTour;
};

#endif /* TOUR_H_ */
