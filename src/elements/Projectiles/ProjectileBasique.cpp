/*
 * ProjectileBasique.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "ProjectileBasique.h"

ProjectileBasique::ProjectileBasique(Coordonnees tCoord, Personnage* tCible, int tDommages) : Projectile(tCoord, tCible, tDommages) {
	vitesse = 15;
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spriteElement.setTexture(pResourcesLoader->textureProjectileBasique);
	spriteElement.setScale(0.5,0.5);
	spriteElement.setPosition(tCoord.posX,tCoord.posY);
}

void ProjectileBasique::toucherEnnemi()
{
	cible->perdrePV(dommages);
	ResourceManager *manager = ResourceManager::getInstance();
	manager->removeProjectile(this);
	delete this;
}

void ProjectileBasique::dessiner(sf::RenderWindow & rWindow){
	rWindow.draw(spriteElement);
}


ProjectileBasique::~ProjectileBasique() {
	// VIDE
}

void ProjectileBasique::avancer()
{
	int xproj = this->coordonnees.getPosX();
	int yproj = this->coordonnees.getPosY();
	int xperso = this->cible->getCoordonnees().getPosX() + 12;
	int yperso = this->cible->getCoordonnees().getPosY() + 20;

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
	spriteElement.setPosition(xproj, yproj);

	if(((xperso-xproj)+(yperso-yproj)) == 0){
		this->toucherEnnemi();
	}
}

