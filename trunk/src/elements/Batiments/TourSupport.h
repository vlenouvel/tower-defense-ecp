/*
 * TourSupport.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef TOURSUPPORT_H_
#define TOURSUPPORT_H_

#include "Tour.h"
#include <math.h>
#include "../../ResourceManager.h"
#include "TourAttaque.h"

class TourSupport : public Tour {
public:
	TourSupport(Coordonnees tCoord);
	virtual ~TourSupport();
	void agir();
	void handleEvent(sf::Event event);
	void monterNiveau();
	void dessiner(sf::RenderWindow &pWindow);
	bool isTourAttaque();
	void recalculerAmelioration();
	void vendreBatiment();
private:
	void enleverAmelioration();
	void ajouterAmelioration(int valeur);

};

#endif /* TOURSUPPORT_H_ */
