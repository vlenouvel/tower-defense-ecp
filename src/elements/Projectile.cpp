/*
 * Projectile.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "Projectile.h"

Projectile::Projectile(Coordonnees tCoord, Personnage* tCible, int tDamage) : coordonnees(tCoord), cible(tCible), dommages(tDamage) {
	// TODO Auto-generated constructor stub

}

Projectile::~Projectile() {
	// TODO Auto-generated destructor stub
}

void Projectile::dessiner(sf::RenderWindow &pWindow){
	// TO DO
}

void Projectile::agir()
{
	this->avancer();
}
