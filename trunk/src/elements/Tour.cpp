/*
 * Tour.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "Tour.h"
#include "../ResourceManager.h"
#include "../ResourcesLoader.h"
#include <iostream>
Tour::Tour(Coordonnees tCoord) : Batiment(tCoord), niveau(1) {
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	sonCreationTour.setBuffer(pResourcesLoader->bufferCreationTour);
	sonCreationTour.play();
}

void Tour::monterNiveau()
{
	niveau++;
	prix += (int)(prix*0.75);
}

Tour::~Tour() {
}

void Tour::dessiner(sf::RenderWindow &pWindow){
	// TO DO
}

// Verifie le jouer a assez d'argent pour ameliorer sa tour d'un niveau
bool Tour::verifierAmelioration() {

	ResourceManager* manager = ResourceManager::getInstance();

	int argent = manager->getRessources()->getArgent();

	// TODO Revoir prix d'amelioration de tour
	return(argent >= (int)(prix*0.75));
}

int Tour::getNiveau()
{
	return niveau;
}

bool Tour::isTourAttaque()
{
	return false;
}

int Tour::getDommages()
{
	return 0;
}
