/*
 * ProjectileBasique.h
 *
 *  Created on: 13 nov. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef PROJECTILEBASIQUE_H_
#define PROJECTILEBASIQUE_H_

#include "Projectile.h"

class ProjectileBasique: public Projectile {
public:
	ProjectileBasique(Coordonnees tCoord, Personnage* tCible, int tDommages);
	void toucherEnnemi();
	virtual ~ProjectileBasique();
	void dessiner(sf::RenderWindow & rWindow);
};

#endif /* PROJECTILEBASIQUE_H_ */
