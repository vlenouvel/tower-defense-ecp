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
	// TODO Auto-generated destructor stub
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

void Projectile::avancer()
{
	int xproj = this->coordonnees.getPosX();
	int yproj = this->coordonnees.getPosY();
	int xperso = this->cible->getCoordonnees().getPosX();
	int yperso = this->cible->getCoordonnees().getPosY();

	double alpha = this->vitesse/sqrt(pow((float)(xperso-xproj),2)+pow((float)(yperso-yproj),2));
	if (alpha > 1)
	{
		// Si alpha > 1, cela veut dire que le projectile s'apprete a parcourir une
		// distance plus grande que celle qui le separe de la cible
		alpha = 1;
	}
	xproj += (int)floor(alpha*(xperso-xproj));
	yproj += (int)floor(alpha*(yperso-yproj));
	this->coordonnees.setPosX(xproj);
	this->coordonnees.setPosY(yproj);
	spriteProjectile.setPosition(xproj, yproj);

	if(((xperso-xproj)+(yperso-yproj)) == 0){
		this->toucherEnnemi();
	}
}

