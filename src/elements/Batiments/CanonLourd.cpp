/*
 * CanonLourd.cpp
 *
 *  TowerDefense ECP
 *      
 */

#include "CanonLourd.h"

CanonLourd::CanonLourd(Coordonnees tCoord) : TourAttaque(tCoord) {
	pCibler = ComportementCiblage::ciblerZone;
	comportementChoisi = ComportementCiblage::Zone;
	ConfigManager *configManager = ConfigManager::getInstance();
	prix = configManager->mapTourCanon["prix"];
	attackRange = configManager->mapTourCanon["portee"];
	attackDamage = configManager->mapTourCanon["attaque"];
	rayonExplosion = configManager->mapTourCanon["rayonExplosion"];
	timeBetweenAttacks = sf::milliseconds(configManager->mapTourCanon["temps"]);
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spriteElement.setTexture(pResourcesLoader->textureCanonLourd);
	spriteElement.setScale(0.5,0.5);
	spriteElement.setPosition(floor(float(tCoord.getPosX()/40))*40,floor(float(tCoord.getPosY()/40))*40);
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
	// VIDE
}

void CanonLourd::dessiner(sf::RenderWindow & rWindow){
	rWindow.draw(spriteElement);
}

