/*
 * TourAttaqueBasique.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "TourAttaqueBasique.h"
#include <iostream>
#include <cmath>

TourAttaqueBasique::TourAttaqueBasique(Coordonnees tCoord) : TourAttaque(tCoord) {
	ConfigManager *configManager = ConfigManager::getInstance();
	prix = configManager->mapTourBasique["prix"];
	attackRange = configManager->mapTourBasique["portee"];
	attackDamage = configManager->mapTourBasique["attaque"];
	timeBetweenAttacks = sf::milliseconds(configManager->mapTourBasique["temps"]);
	pCibler = ComportementCiblage::ciblerPremier;
	comportementChoisi = ComportementCiblage::Premier;
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spriteElement.setTexture(pResourcesLoader->textureTourAttaqueBasique);
	spriteElement.setScale(0.5,0.5);
	spriteElement.setPosition((float)(tCoord.posX/40)*40,floor((float)(tCoord.posY/40))*40);
	sonTirTourAttaqueBasique.setBuffer(pResourcesLoader->bufferTirTourAttaqueBasique);
	sonTirTourAttaqueBasique.setVolume(40);
	calculerValeursAmeliorees();
}

void TourAttaqueBasique::attaque(Personnage* (*fonctionCiblage)(std::vector<Personnage*> ciblesPossibles))
{
	ResourceManager *manager = ResourceManager::getInstance();
	Personnage *cible = fonctionCiblage(this->ciblesPossibles);
	Coordonnees coord = this->coordonnees;
	ProjectileBasique *projo = new ProjectileBasique(coord, cible, attackDamageBuffed);
	manager->addProjectile((Projectile*)projo);
	sonTirTourAttaqueBasique.play();
}

TourAttaqueBasique::~TourAttaqueBasique() {
	// VIDE
}

void TourAttaqueBasique::dessiner(sf::RenderWindow & rWindow){
	rWindow.draw(spriteElement);
}

