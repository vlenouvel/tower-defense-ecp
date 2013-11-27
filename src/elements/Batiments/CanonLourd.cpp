/*
 * CanonLourd.cpp
 *
 *  TowerDefense ECP
 *      
 */

#include "CanonLourd.h"
#include <iostream>
#include <cmath>


CanonLourd::CanonLourd(Coordonnees tCoord) : TourAttaque(tCoord) {
	pCibler = ComportementCiblage::ciblerPremier;
	comportementChoisi = ComportementCiblage::Premier;
	ConfigManager *configManager = ConfigManager::getInstance();
	prix = configManager->mapTourCanon["prix"];
	attackRange = configManager->mapTourCanon["portee"];
	attackDamage = configManager->mapTourCanon["attaque"];
	rayonExplosion = configManager->mapTourCanon["rayonExplosion"];
	timeBetweenAttacks = sf::milliseconds(configManager->mapTourCanon["temps"]);
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	textureCanonLourd = pResourcesLoader->textureCanonLourd;
	spriteCanonLourd.setTexture(textureCanonLourd);
	spriteCanonLourd.setScale(0.5,0.5);
	spriteCanonLourd.setPosition(floor(float(tCoord.posX/40))*40,floor(float(tCoord.posY/40))*40);
	sonTirCanonLourd.setBuffer(pResourcesLoader->bufferTirCanonLourd);
	sonTirCanonLourd.setVolume(40);
	calculerValeursAmeliorees();
}

void CanonLourd::attaque(Personnage* (*fonctionCiblage)(std::vector<Personnage*> ciblesPossibles))
{
	ResourceManager *manager = ResourceManager::getInstance();
	Personnage *cible = fonctionCiblage(this->ciblesPossibles);
	Coordonnees coord = this->coordonnees;
	Missile *projo = new Missile(coord, cible, attackDamageBuffed, rayonExplosion);
	manager->addProjectile((Projectile*)projo);
	sonTirCanonLourd.play();
}

CanonLourd::~CanonLourd() {
	// TODO Auto-generated destructor stub
}

void CanonLourd::dessiner(sf::RenderWindow & rWindow){
	rWindow.draw(spriteCanonLourd);
}

