/*
 * TourDeGlace.cpp
 *
 *  TowerDefense ECP
 *      
 */

#include "TourDeGlace.h"
#include <cmath>
#define PI 3.14159265

TourDeGlace::TourDeGlace(Coordonnees tCoord) : TourAttaque(tCoord), rayonExplosion(10) {
	ConfigManager *configManager = ConfigManager::getInstance();
	prix = configManager->mapTourDeGlace["prix"];
	attackRange = configManager->mapTourDeGlace["portee"];
	attackDamage = configManager->mapTourDeGlace["attaque"];
	timeBetweenAttacks = sf::milliseconds(configManager->mapTourDeGlace["temps"]);
	pCibler = ComportementCiblage::ciblerPlusProche;
	comportementChoisi = ComportementCiblage::PlusProche;
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spriteElement.setTexture(pResourcesLoader->textureTourDeGlace);
	spriteEnvironementTourDeGlace.setTexture(pResourcesLoader->textureEnvironnementGlace);
	spriteElement.setScale(0.5,0.5);
	spriteElement.setPosition(floor(float(tCoord.getPosX()/40))*40,floor(float(tCoord.getPosY()/40))*40);
	spriteEnvironementTourDeGlace.setScale(0.68,0.76);
	spriteEnvironementTourDeGlace.setPosition(floor(float(tCoord.getPosX()/40))*40-25,floor(float(tCoord.getPosY()/40))*40-30);
	rotation = 0;
	sonTirTourGlace.setBuffer(pResourcesLoader->bufferTirTourGlace);
	calculerValeursAmeliorees();
}

void TourDeGlace::attaque(Personnage* (*fonctionCiblage)(std::vector<Personnage*> ciblesPossibles))
{
	ResourceManager *manager = ResourceManager::getInstance();
	Personnage *cible = fonctionCiblage(this->ciblesPossibles);
	Coordonnees coord = this->coordonnees;
	TirDeGlace *projo = new TirDeGlace(coord, cible, attackDamageBuffed, rayonExplosion);
	manager->addProjectile((Projectile*)projo);
	sonTirTourGlace.play();
}

TourDeGlace::~TourDeGlace() {
	// VIDE
}

void TourDeGlace::actionSpeciale(){
	ResourceManager *manager = ResourceManager::getInstance();
	std::vector<Personnage *> persosProches;
	for (unsigned int i=0; i<manager->getPersonnage().size();i++){
		if (pow((double)(manager->getPersonnage()[i]->getCoordonnees().getPosX() - this->coordonnees.getPosX()),2) + pow((double)(manager->getPersonnage()[i]->getCoordonnees().getPosY() - this->coordonnees.getPosY()),2) < 4000){
			persosProches.push_back(manager->getPersonnage()[i]);
		}
	}
	for (unsigned int i=0;i<persosProches.size();i++){
		persosProches[i]->setPourcentageVitesseMalus(50);
	}
	persosProches.clear();
	rotation++;
	spriteEnvironementTourDeGlace.setRotation(rotation);
	int abscisseEnvironementGlace = -50*(cos(rotation*PI/180) - sin(rotation*PI/180)) + floor(float(this->coordonnees.getPosX()/40))*40+19;
	int ordonneeEnvironementGlace = - 50*(sin(rotation*PI/180) + cos(rotation*PI/180)) + floor(float(this->coordonnees.getPosY()/40))*40+20;
	spriteEnvironementTourDeGlace.setPosition(abscisseEnvironementGlace,ordonneeEnvironementGlace);
}

void TourDeGlace::dessiner(sf::RenderWindow & rWindow){
	rWindow.draw(spriteEnvironementTourDeGlace);
	rWindow.draw(spriteElement);
}
