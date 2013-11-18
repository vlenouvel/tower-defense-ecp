/*
 * Batiment.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "Batiment.h"
#include "../ResourceManager.h"

Batiment::Batiment(int tPrix, Coordonnees tCoord) : coordonnees(tCoord), prix(tPrix) {
	ResourceManager* manager = ResourceManager::getInstance();

	manager->getRessources()->perdreArgent(prix);
}

Batiment::~Batiment() {

}

void Batiment::dessiner(sf::RenderWindow &pWindow){
	// TO DO
}

bool Batiment::verifierAchat(int prixBat) {
	ResourceManager* manager = ResourceManager::getInstance();

	int argent = manager->getRessources()->getArgent();

	if (argent < prixBat) {
		return false;
	}

	return true;
}

Coordonnees Batiment::getCoordonnees()
{
	return coordonnees;
}
