/*
 * GenerateurVague.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "GenerateurVague.h"
#include <iostream>
#include <sstream>

GenerateurVague::GenerateurVague() {
	niveau = 0;

	// definition du temps d'attente entre deux vagues
	tempsEntreVague = sf::seconds((float)5);


	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	font = pResourcesLoader->police;
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
	ResourceManager *manager = ResourceManager::getInstance();
	Vague* pVague = new Vague(niveau);
	manager->addVague(pVague);
	++niveau;
}

void GenerateurVague::dessiner(sf::RenderWindow &pWindow){
		ResourceManager* manager = ResourceManager::getInstance();

		ostringstream ss;
		ss << "\n\n\n\nVague:";
		ss << niveau;

		texteNiveau.setString(ss.str());
		pWindow.draw(texteNiveau);
}

GenerateurVague::~GenerateurVague() {
	// TODO Auto-generated destructor stub
}

