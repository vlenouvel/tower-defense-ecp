/*
 * TableauDeBord.cpp
 *
 *  TowerDefense ECP
 *      
 */

#include "TableauDeBord.h"
#include <string>
#include <sstream>


TableauDeBord::TableauDeBord() {
	ResourcesLoader *pResourcesLoader = ResourcesLoader::getInstance();
	textureTableauDeBord = pResourcesLoader->textureRessources;
	spriteTableauDeBord.setTexture(textureTableauDeBord);
	spriteTableauDeBord.setScale(1,3);
	spriteTableauDeBord.setPosition(720,100);
	font = pResourcesLoader->policeTableauDeBord;
	texteTableauDeBord.setFont(font);
	texteTableauDeBord.setCharacterSize(48);
	texteTableauDeBord.setColor(sf::Color::White);
	texteTableauDeBord.setStyle(sf::Text::Bold);
	texteTableauDeBord.setPosition(720,0);

	textureCanonLourd = pResourcesLoader->textureCanonLourd;
	spriteCanonLourd.setTexture(textureCanonLourd);
	spriteCanonLourd.setScale(0.5,0.5);
	spriteCanonLourd.setPosition(710,300);

	textureTourAttaqueBasique = pResourcesLoader->textureTourAttaqueBasique;
	spriteTourAttaqueBasique.setTexture(textureTourAttaqueBasique);
	spriteTourAttaqueBasique.setScale(0.5,0.5);
	spriteTourAttaqueBasique.setPosition(760,300);

	texteNiveauTour.setFont(font);
	texteNiveauTour.setCharacterSize(8);
	texteNiveauTour.setColor(sf::Color::White);
	texteNiveauTour.setStyle(sf::Text::Bold);
	texteNiveauTour.setPosition(710, 360);

	textureLevelUpBouton = pResourcesLoader->textureLevelUpBouton;
	spriteLevelUpBouton.setTexture(textureLevelUpBouton);
	spriteLevelUpBouton.setScale(0.75, 0.75);
	spriteLevelUpBouton.setPosition(710, 400);
}

TableauDeBord::~TableauDeBord() {
	// TODO Auto-generated destructor stub
}

void TableauDeBord::dessiner(sf::RenderWindow &pWindow){
	ResourceManager* manager = ResourceManager::getInstance();

	pWindow.draw(spriteTableauDeBord);
	pWindow.draw(texteTableauDeBord);
	pWindow.draw(spriteCanonLourd);
	pWindow.draw(spriteTourAttaqueBasique);

	if (manager->getTourSelectionnee()!=0)
	{
		ostringstream stringNiveauTour;
		stringNiveauTour << manager->getTourSelectionnee()->getNiveau();
		texteNiveauTour.setString("Niveau tour:" + stringNiveauTour.str());
		pWindow.draw(texteNiveauTour);
		pWindow.draw(spriteLevelUpBouton);
	}
}
