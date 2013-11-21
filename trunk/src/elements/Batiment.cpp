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

void Batiment::dessiner(sf::RenderWindow &pWindow){
	// TO DO
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
	pResourceManager->getRessources()->gagnerArgent((int)(prix*0.75));
	pResourceManager->removeBatiment(this);
	pResourceManager->setBatimentSelectionne(0);

	delete this;
}
