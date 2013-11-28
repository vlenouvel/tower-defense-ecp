/*
 * Tour.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "Tour.h"
#include "../../ResourceManager.h"
#include "../../ResourcesLoader.h"
Tour::Tour(Coordonnees tCoord) : Batiment(tCoord), niveau(1) {
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	sonCreationTour.setBuffer(pResourcesLoader->bufferCreationTour);
	sonCreationTour.play();
}

void Tour::monterNiveau()
{
	ResourceManager* pResourceManager = ResourceManager::getInstance();
	ConfigManager *pConfigManager = ConfigManager::getInstance();
	int tauxRevente = pConfigManager->tauxRevente;
	pResourceManager->getRessources()->perdreArgent((int)(prix*tauxRevente/100.));
	niveau++;
	prix += (int)(prix*tauxRevente/100.);
}

Tour::~Tour() {
}

void Tour::dessiner(sf::RenderWindow &pWindow){
	// VIDE
}


// Verifie le jouer a assez d'argent pour ameliorer sa tour d'un niveau
bool Tour::verifierAmelioration() {

	ResourceManager* manager = ResourceManager::getInstance();

	int argent = manager->getRessources()->getArgent();
	ConfigManager *pConfigManager = ConfigManager::getInstance();
		int tauxRevente = pConfigManager->tauxRevente;
	return(argent >= (int)(prix*tauxRevente/100.));
}

int Tour::getNiveau()
{
	return niveau;
}

bool Tour::isTour()
{
	return true;
}
