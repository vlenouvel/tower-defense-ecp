/*
 * ProjectileBasique.cpp
 *
 *  Created on: 13 nov. 2013
 *      Author: Vincent Lenouvel
 */

#include "ProjectileBasique.h"

ProjectileBasique::ProjectileBasique(Coordonnees tCoord, Personnage* tCible, int tDommages) : Projectile(tCoord, tCible, tDommages) {

}

void ProjectileBasique::toucherEnnemi()
{
	cible->perdrePV(dommages);
	delete this;
}

ProjectileBasique::~ProjectileBasique() {
	// TODO Auto-generated destructor stub
}

