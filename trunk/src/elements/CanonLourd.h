/*
 * CanonLourd.h
 *
 *  Created on: 15 nov. 2013
 *      Author: Vincent Carrier
 */

#ifndef CANONLOURD_H_
#define CANONLOURD_H_

#include "TourAttaque.h"
#include "ProjectileExplosif.h"
#include "Projectile.h"

class CanonLourd: public TourAttaque {
public:
	CanonLourd(int tPrix, Coordonnees tCoord);
	virtual ~CanonLourd();
	void dessiner(sf::RenderWindow & rWindow);

private:
	void attaque(Personnage* (*fonctionCiblage)(std::vector<Personnage*>* ciblesPossibles));
	int rayonExplosion;
	sf::Texture textureCanonLourd;
	sf::Sprite spriteCanonLourd;
};

#endif /* CANONLOURD_H_ */
