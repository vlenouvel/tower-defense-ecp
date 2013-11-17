/*
 * CanonLourd.cpp
 *
 *  TowerDefense ECP
 *      
 */

#include "CanonLourd.h"
#include <iostream>
#include <cmath>


CanonLourd::CanonLourd(int tPrix, Coordonnees tCoord) : TourAttaque(tPrix, tCoord), rayonExplosion(10) {
	pCibler = ComportementCiblage::ciblerPremier;
	attackDamage = 10;
	attackRange = 1000;
	timeBetweenAttacks = sf::seconds((float)2);
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	textureCanonLourd = pResourcesLoader->textureCanonLourd;
	spriteCanonLourd.setTexture(textureCanonLourd);
	spriteCanonLourd.setScale(0.5,0.5);
	spriteCanonLourd.setPosition(floor(float(tCoord.posX/40))*40,floor(float(tCoord.posY/40))*40);
	sonTirCanonLourd.setBuffer(pResourcesLoader->bufferTirCanonLourd);
	sonTirCanonLourd.setVolume(40);
}

void CanonLourd::attaque(Personnage* (*fonctionCiblage)(std::vector<Personnage*> ciblesPossibles))
{
	ResourceManager *manager = ResourceManager::getInstance();
	Personnage *cible = fonctionCiblage(this->ciblesPossibles);
	Coordonnees coord = this->coordonnees;
	ProjectileExplosif *projo = new ProjectileExplosif(coord, cible, attackDamage, rayonExplosion);
	manager->addProjectile((Projectile*)projo);
	sonTirCanonLourd.play();
}

CanonLourd::~CanonLourd() {
	// TODO Auto-generated destructor stub
}

void CanonLourd::dessiner(sf::RenderWindow & rWindow){
	rWindow.draw(spriteCanonLourd);
}
