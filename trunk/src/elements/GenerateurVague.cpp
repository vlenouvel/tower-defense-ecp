/*
 * GenerateurVague.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "GenerateurVague.h"
#include <iostream>

GenerateurVague::GenerateurVague() {
	niveau = 1;

	// definition du temps d'attente entre deux vagues
	tempsEntreVague = sf::seconds((float)5);

}

void GenerateurVague::agir()
{
	if(horlogeVague.getElapsedTime() >= tempsEntreVague)
	{
		horlogeVague.restart();
		this->genererVague();
	}
}

void GenerateurVague::genererVague()
{
	ResourceManager *manager = ResourceManager::getInstance();
	Vague* pVague = new Vague(niveau);
	manager->addVague(pVague);
	niveau++;
}

GenerateurVague::~GenerateurVague() {
	// TODO Auto-generated destructor stub
}

