/*
 * Projectile.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include <cmath>
#include "Projectile.h"


Projectile::Projectile(Coordonnees tCoord, Personnage* tCible, int tDommages) : dommages(tDommages), vitesse(0), coordonnees(tCoord), cible(tCible){

}

Projectile::~Projectile() {
	// TODO Auto-generated destructor stub
}

void Projectile::dessiner(sf::RenderWindow &pWindow){
	// TODO
}

void Projectile::agir()
{
	this->avancer();
}

void Projectile::avancer()
{
	double xproj = this->coordonnees.getPosX();
	double yproj = this->coordonnees.getPosY();
	double xperso = this->cible->getCoordonnees().getPosX();
	double yperso = this->cible->getCoordonnees().getPosY();

	double alpha = this->vitesse/sqrt(pow((xperso-xproj),2)+pow((yperso-yproj),2));

	if (alpha > 1)
	{
		alpha = 1; // Si alpha > 1, cela veut dire que le projectile s'apprete a parcourir une distance plus grande que celle qui le separe de la cible
	}
	xproj += round (alpha*(xperso-xproj));
	yproj += round (alpha*(yperso-yproj));
	this->coordonnees.setPosX(xproj);
	this->coordonnees.setPosY(yproj);

	if(((xperso-xproj)+(yperso-yproj)) == 0){
		this->toucherEnnemi();
	}
}
