/*
 * Projectile.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "Projectile.h"
#include "math.h"

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
	int xproj = this->coordonnees.getPosX();
	int yproj = this->coordonnees.getPosY();
	int xperso = this->cible->getCoordonnees().getPosX();
	int yperso = this->cible->getCoordonnees().getPosY();

	/*float alpha = this->vitesse/sqrt(((xperso-xproj)^(2))+((yperso-yproj)^(2)));

	if (alpha > 1)
	{
		alpha = 1; // Si alpha > 1, cela veut dire que le projectile s'apprete à parcourir une distance plus grande que celle qui le sépare de la cible
	}
	xproj += (int)round(alpha*(xperso-xproj));
	yproj += (int)round(alpha*(yperso-yproj));
	this->coordonnees.setPosX(xproj);
	this->coordonnees.setPosY(yproj);

	if(((xperso-xproj)+(yperso-yproj)) == 0){
		this->toucherEnnemi();
	}*/
}
