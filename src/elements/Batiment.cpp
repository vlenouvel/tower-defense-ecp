/*
 * Batiment.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "Batiment.h"
#include "../ResourceManager.h"

Batiment::Batiment(Coordonnees tCoord) : coordonnees(tCoord) {
	prix = 0;
}

Batiment::~Batiment() {
	// VIDE
}

int Batiment::getPrix()
{
	return prix;
}

bool Batiment::verifierAchat()
{
	ResourceManager *pResourceManager = ResourceManager::getInstance();
	int argent = pResourceManager->getRessources()->getArgent();
	return (argent >= prix);
}

Coordonnees Batiment::getCoordonnees()
{
	return coordonnees;
}
void Batiment::vendreBatiment()
{
	//TODO Equilibrage : prix de vente
	//TODO Coherence avec affichage
	ResourceManager* pResourceManager = ResourceManager::getInstance();
	ConfigManager *pConfigManager = ConfigManager::getInstance();
	int tauxRevente = pConfigManager->tauxRevente;
	pResourceManager->getRessources()->gagnerArgent((int)(prix*tauxRevente/100.));
	pResourceManager->removeBatiment(this);
	pResourceManager->setBatimentSelectionne(0);

	delete this;
}
