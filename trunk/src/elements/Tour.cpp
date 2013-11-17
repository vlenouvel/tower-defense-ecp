/*
 * Tour.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "Tour.h"
#include "../ResourceManager.h"
#include "../ResourcesLoader.h"

Tour::Tour(int tPrix, Coordonnees tCoord) : Batiment(tPrix, tCoord) , niveau(1) {
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	sonCreationTour.setBuffer(pResourcesLoader->bufferCreationTour);
	sonCreationTour.play();
}

void Tour::monterNiveau()
{
	niveau++;
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
	if (argent < prix * (niveau + 1)) {
		return false;
	}

	return true;
}
