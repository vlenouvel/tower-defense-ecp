/*
 * ProjectileBasique.cpp
 *
 *  Created on: 13 nov. 2013
 *      Author: Vincent Lenouvel
 */

#include "ProjectileBasique.h"

ProjectileBasique::ProjectileBasique(Coordonnees tCoord, Personnage* tCible, int tDommages) : Projectile(tCoord, tCible, tDommages) {
	textureProjectile.loadFromFile("resources/textures/textureProjectileBasique.png");
	spriteProjectile.setTexture(textureProjectile);
	spriteProjectile.setScale(0.5,0.5);
	spriteProjectile.setPosition(tCoord.posX,tCoord.posY);
}

void ProjectileBasique::toucherEnnemi()
{
	cible->perdrePV(dommages);
	ResourceManager *manager = ResourceManager::getInstance();
	manager->removeProjectile(this);
}

void ProjectileBasique::dessiner(sf::RenderWindow & rWindow){
	rWindow.draw(spriteProjectile);
}


ProjectileBasique::~ProjectileBasique() {
	// TODO Auto-generated destructor stub
}

