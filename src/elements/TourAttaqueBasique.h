/*
 * TourAttaqueBasique.h
 *
 *  Created on: 13 nov. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef TOURATTAQUEBASIQUE_H_
#define TOURATTAQUEBASIQUE_H_

#include "TourAttaque.h"
#include "ProjectileBasique.h"

class TourAttaqueBasique: public TourAttaque {
public:
	TourAttaqueBasique(int tPrix, Coordonnees tCoord);
	virtual ~TourAttaqueBasique();
	void dessiner(sf::RenderWindow & rWindow);

private:
	void attaque(Personnage* (*fonctionCiblage)(std::vector<Personnage*>* ciblesPossibles));
	sf::Texture textureTourAttaqueBasique;
	sf::Sprite spriteTourAttaqueBasique;
};

#endif /* TOURATTAQUEBASIQUE_H_ */
