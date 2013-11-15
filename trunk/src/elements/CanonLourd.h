/*
 * CanonLourd.h
 *
 *  Created on: 15 nov. 2013
 *      Author: Vincent Carrier
 */

#ifndef CANONLOURD_H_
#define CANONLOURD_H_

#include "TourAttaque.h"

class CanonLourd: public TourAttaque {
public:
	CanonLourd(int tPrix, Coordonnees tCoord, int tNiveau);
	virtual ~CanonLourd();
	void dessiner(sf::RenderWindow & rWindow);

private:
	void attaque(void (*fonctionCiblage)());
	sf::Texture textureCanonLourd;
	sf::Sprite spriteCanonLourd;
};

#endif /* CANONLOURD_H_ */