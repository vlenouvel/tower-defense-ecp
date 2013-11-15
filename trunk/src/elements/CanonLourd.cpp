/*
 * CanonLourd.cpp
 *
 *  Created on: 15 nov. 2013
 *      Author: Vincent Carrier
 */

#include "CanonLourd.h"
#include <iostream>
#include <cmath>

CanonLourd::CanonLourd(int tPrix, Coordonnees tCoord) : TourAttaque(tPrix, tCoord), rayonExplosion(10) {
	attackDamage = 10;
	attackRange = 100;
	textureCanonLourd.loadFromFile("resources/textures/textureCanonLourd.jpg");
	spriteCanonLourd.setTexture(textureCanonLourd);
	spriteCanonLourd.setScale(0.5,0.5);
	spriteCanonLourd.setPosition(floor(float(tCoord.posX/40))*40,floor(float(tCoord.posY/40))*40);
}

void CanonLourd::attaque(Personnage* (*fonctionCiblage)(std::vector<Personnage*>* ciblesPossibles))
{
	ResourceManager *manager = ResourceManager::getInstance();
	Personnage *cible = fonctionCiblage(&this->ciblesPossibles);
	Coordonnees coord = this->coordonnees;
	ProjectileExplosif *projo = new ProjectileExplosif(coord, cible, attackDamage, rayonExplosion);
	manager->addProjectile((Projectile*)projo);
}

CanonLourd::~CanonLourd() {
	// TODO Auto-generated destructor stub
}

void CanonLourd::dessiner(sf::RenderWindow & rWindow){
	rWindow.draw(spriteCanonLourd);
}
