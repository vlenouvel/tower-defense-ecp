/*
 * GenerateurVague.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "GenerateurVague.h"
#include <sstream>

GenerateurVague::GenerateurVague() {
	niveau = 1;

	// definition du temps d'attente entre deux vagues
	tempsEntreVague = sf::seconds(15.f);


	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	font = pResourcesLoader->policeMenu;
	texteNiveau.setFont(font);
	texteNiveau.setCharacterSize(14);
	texteNiveau.setColor(sf::Color::White);
	texteNiveau.setStyle(sf::Text::Bold);
	texteNiveau.setPosition(715,0);
	texteNiveau.setFont(font);

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
	ResourceManager *pResourceManager = ResourceManager::getInstance();
	Vague* pVague = new Vague(niveau);

	if(pResourceManager->getVague() != 0)
		delete pResourceManager->getVague();
	pResourceManager->addVague(pVague);
	++niveau;
	pResourceManager->getRessources()->setVagues(niveau-1);
}

GenerateurVague::~GenerateurVague() {
	// VIDE
}

