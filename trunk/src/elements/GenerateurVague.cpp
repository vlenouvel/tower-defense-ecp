/*
 * GenerateurVague.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "GenerateurVague.h"

GenerateurVague::GenerateurVague() {
	niveau = 1;

	// definition du temps d'attente entre deux vagues
	tempsEntreVague = sf::seconds((float)10);

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

