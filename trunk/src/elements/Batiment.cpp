/*
 * Batiment.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "Batiment.h"
#include "../ResourceManager.h"

Batiment::Batiment(int tPrix, Coordonnees tCoord) : coordonnees(tCoord), prix(tPrix) {

}

Batiment::~Batiment() {

}

void Batiment::dessiner(sf::RenderWindow &pWindow){
	// TO DO
}

bool Batiment::verifierAchat() {
	ResourceManager* manager = ResourceManager::getInstance();

	int argent = manager->getRessources()->getArgent();

	if (argent < prix) {
		return false;
	}

	return true;
}
