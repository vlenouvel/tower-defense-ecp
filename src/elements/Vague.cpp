/*
 * Vague.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "Vague.h"
#include <iostream>

Vague::Vague(int niveau) {
	// TODO Fixer le bon nombre de type d'unites
	nombreType = 1;
	niveauType = niveau % nombreType;
	std::cout << "Vague creee" << std::endl;
}

void Vague::genererPersonnage(int nbPersonnage)
{
	ResourceManager* manager = ResourceManager::getInstance();

	Coordonnees coordonneesDepart(0,10);

	for (int i = 0; i < nbPersonnage; ++i) {
		Personnage* pPersonnage = new Personnage(10, 10, 10, coordonneesDepart);
		manager->addPersonnage(pPersonnage);
		std::cout << "Perso " << i << std::endl;

	}
}

void Vague::agir()
{
	/*sf::Time timeElapsed = horlogePop.getElapsedTime();
	if (timeElapsed > tempsEntrePop)
	{
		horlogePop.restart();
		genererPersonnage();
	}*/
	int nbPersonnage = 5;
	genererPersonnage(nbPersonnage);
}

Vague::~Vague() {
	// TODO Auto-generated destructor stub
}

