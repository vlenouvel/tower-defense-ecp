/*
 * ProjectileBasique.cpp
 *
 *  Created on: 13 nov. 2013
 *      Author: Vincent Lenouvel
 */

#include "ProjectileBasique.h"

ProjectileBasique::ProjectileBasique(Coordonnees tCoord, Personnage* tCible, int tDommages) : Projectile(tCoord, tCible, tDommages) {
	textureProjectileBasique.loadFromFile("resources/textures/textureProjectileBasique.png");
	spriteProjectileBasique.setTexture(textureProjectileBasique);
	spriteProjectileBasique.setScale(0.5,0.5);
	spriteProjectileBasique.setPosition(tCoord.posX,tCoord.posY);
}

void ProjectileBasique::toucherEnnemi()
{
	cible->perdrePV(dommages);
	delete this;
}

void ProjectileBasique::dessiner(sf::RenderWindow & rWindow){
	rWindow.draw(spriteProjectileBasique);
}

ProjectileBasique::~ProjectileBasique() {
	// TODO Auto-generated destructor stub
}

