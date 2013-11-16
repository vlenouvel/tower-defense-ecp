/*
 * ProjectileExplosif.h
 *
 *  Created on: 14 nov. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef PROJECTILEEXPLOSIF_H_
#define PROJECTILEEXPLOSIF_H_

#include "Projectile.h"
#include "../ResourceManager.h"
#include "math.h"

class ProjectileExplosif: public Projectile {
public:
	ProjectileExplosif(Coordonnees tCoord, Personnage* tCible, int tDommages, int tRayonExplosion);
	void toucherEnnemi();
	virtual ~ProjectileExplosif();
	void dessiner(sf::RenderWindow & rWindow);

private:
	int rayonExplosion;
};

#endif /* PROJECTILEEXPLOSIF_H_ */
