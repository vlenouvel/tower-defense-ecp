/*
 * Batiment.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "Batiment.h"
#include "../ResourceManager.h"

Batiment::Batiment(Coordonnees tCoord) : coordonnees(tCoord) {
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

