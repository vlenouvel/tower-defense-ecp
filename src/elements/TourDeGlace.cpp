/*
 * TourDeGlace.cpp
 *
 *  TowerDefense ECP
 *      
 */

#include "TourDeGlace.h"
#include <iostream>
#include <cmath>
#define PI 3.14159265

TourDeGlace::TourDeGlace(Coordonnees tCoord) : TourAttaque(tCoord), rayonExplosion(10) {
	prix = 80;
	attackRange = 500;
	attackDamage = 0;
	timeBetweenAttacks = sf::milliseconds(2000);
	pCibler = ComportementCiblage::ciblerPremier;
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spriteTourDeGlace.setTexture(pResourcesLoader->textureTourDeGlace);
	spriteEnvironementTourDeGlace.setTexture(pResourcesLoader->textureEnvironnementGlace);
	spriteTourDeGlace.setScale(0.27,0.28);
	spriteTourDeGlace.setPosition(floor(float(tCoord.posX/40))*40,floor(float(tCoord.posY/40))*40);
	spriteEnvironementTourDeGlace.setScale(0.68,0.76);
	spriteEnvironementTourDeGlace.setPosition(floor(float(tCoord.posX/40))*40-30,floor(float(tCoord.posY/40))*40-30);
	rotation = 0;
}

void TourDeGlace::attaque(Personnage* (*fonctionCiblage)(std::vector<Personnage*> ciblesPossibles))
{
	ResourceManager *manager = ResourceManager::getInstance();
	Personnage *cible = fonctionCiblage(this->ciblesPossibles);
	Coordonnees coord = this->coordonnees;
	TirDeGlace *projo = new TirDeGlace(coord, cible, attackDamage, rayonExplosion);
	manager->addProjectile((Projectile*)projo);

}

TourDeGlace::~TourDeGlace() {
	// TODO Auto-generated destructor stub
}

void TourDeGlace::actionSpeciale(){
	ResourceManager *manager = ResourceManager::getInstance();
	vector<Personnage *> persosProches;
	for (unsigned int i=0; i<manager->getPersonnage().size();i++){
		if (pow((double)(manager->getPersonnage()[i]->coordonnees.getPosX() - this->coordonnees.getPosX()),2) + pow((double)(manager->getPersonnage()[i]->coordonnees.getPosY() - this->coordonnees.getPosY()),2) < 4000){
			persosProches.push_back(manager->getPersonnage()[i]);
		}
	}
	for (unsigned int i=0;i<persosProches.size();i++){
		persosProches[i]->pourcentageVitesseMalus += 1;
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
	rWindow.draw(spriteTourDeGlace);
}
