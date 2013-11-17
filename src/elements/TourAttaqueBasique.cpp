/*
 * TourAttaqueBasique.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "TourAttaqueBasique.h"
#include <iostream>
#include <cmath>

TourAttaqueBasique::TourAttaqueBasique(int tPrix, Coordonnees tCoord) : TourAttaque(tPrix, tCoord) {

	attackRange = 100;
	attackDamage = 2;
	timeBetweenAttacks = sf::milliseconds(100);
	pCibler = ComportementCiblage::ciblerPremier;
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	textureTourAttaqueBasique = pResourcesLoader->textureTourAttaqueBasique;
	spriteTourAttaqueBasique.setTexture(textureTourAttaqueBasique);
	spriteTourAttaqueBasique.setScale(0.5,0.5);
	spriteTourAttaqueBasique.setPosition((float)(tCoord.posX/40)*40,floor((float)(tCoord.posY/40))*40);
	sonTirTourAttaqueBasique.setBuffer(pResourcesLoader->bufferTirTourAttaqueBasique);
	sonTirTourAttaqueBasique.setVolume(40);
}

void TourAttaqueBasique::attaque(Personnage* (*fonctionCiblage)(std::vector<Personnage*> ciblesPossibles))
{
	ResourceManager *manager = ResourceManager::getInstance();
	Personnage *cible = fonctionCiblage(this->ciblesPossibles);
	Coordonnees coord = this->coordonnees;
	ProjectileBasique *projo = new ProjectileBasique(coord, cible, attackDamage);
	manager->addProjectile((Projectile*)projo);
	sonTirTourAttaqueBasique.play();
}

TourAttaqueBasique::~TourAttaqueBasique() {
	// TODO Auto-generated destructor stub
}

void TourAttaqueBasique::dessiner(sf::RenderWindow & rWindow){
	rWindow.draw(spriteTourAttaqueBasique);
}

