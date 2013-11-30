/*
 * Projectile.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include <cmath>
#include "Projectile.h"


Projectile::Projectile(Coordonnees tCoord, Personnage* tCible, int tDommages) : dommages(tDommages), vitesse(10), coordonnees(tCoord), cible(tCible){

}

Projectile::~Projectile() {
	// VIDE
}

Personnage* Projectile::getCible()
{
	return cible;
}

void Projectile::setCible(Personnage* nouvelleCible)
{
	cible = nouvelleCible;
}

void Projectile::agir()
{
	if (cible!=0)
	{
		this->avancer();
	}
	else
	{
		delete this;
	}
}
Coordonnees Projectile::getCoordonnees()
{
	return coordonnees;
}


