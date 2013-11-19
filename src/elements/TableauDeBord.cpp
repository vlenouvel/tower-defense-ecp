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

	spriteTourDeGlace.setTexture(pResourcesLoader->textureTourDeGlace);
	spriteTourDeGlace.setScale(0.3,0.3);
	spriteTourDeGlace.setPosition(705,250);

	texteNiveauTour.setFont(font);
	texteNiveauTour.setCharacterSize(7);
	texteNiveauTour.setColor(sf::Color::White);
	texteNiveauTour.setStyle(sf::Text::Bold);
	texteNiveauTour.setPosition(710, 360);

	texteDommagesTour.setFont(font);
	texteDommagesTour.setCharacterSize(7);
	texteDommagesTour.setColor(sf::Color::White);
	texteDommagesTour.setStyle(sf::Text::Bold);
	texteDommagesTour.setPosition(710, 370);

	textureLevelUpBouton = pResourcesLoader->textureLevelUpBouton;
	spriteLevelUpBouton.setTexture(textureLevelUpBouton);
	spriteLevelUpBouton.setScale(0.75, 0.75);
	spriteLevelUpBouton.setPosition(710, 400);

	textureSellBouton = pResourcesLoader->textureSellBouton;
	spriteSellBouton.setTexture(textureSellBouton);
	spriteSellBouton.setPosition(750, 400);

	texteCoutAmelioration.setFont(font);
	texteCoutAmelioration.setCharacterSize(7);
	texteCoutAmelioration.setColor(sf::Color::White);
	texteCoutAmelioration.setStyle(sf::Text::Bold);
	texteCoutAmelioration.setPosition(710, 440);

	textePrixDeVente.setFont(font);
	textePrixDeVente.setCharacterSize(7);
	textePrixDeVente.setColor(sf::Color::White);
	textePrixDeVente.setStyle(sf::Text::Bold);
	textePrixDeVente.setPosition(710,450);
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
	pWindow.draw(spriteTourDeGlace);

	if (manager->getTourSelectionnee()!=0)
	{
		ostringstream stringNiveauTour;
		stringNiveauTour << manager->getTourSelectionnee()->getNiveau();
		texteNiveauTour.setString("Niveau tour : " + stringNiveauTour.str());

		ostringstream stringCoutAmelioration;
		stringCoutAmelioration << (int)(manager->getTourSelectionnee()->getPrix()*0.75); // TODO Verifier coherence avec "verifierAmelioration()"
		texteCoutAmelioration.setString("Ameliorer : " + stringCoutAmelioration.str() + "$");

		ostringstream stringPrixDeVente;
		stringPrixDeVente << (int)(manager->getTourSelectionnee()->getPrix()*0.75); //TODO Coherence avec "vendreTour()"
		textePrixDeVente.setString("Vendre : " + stringPrixDeVente.str() + "$");

		pWindow.draw(texteNiveauTour);
		pWindow.draw(spriteLevelUpBouton);
		pWindow.draw(spriteSellBouton);
		pWindow.draw(texteCoutAmelioration);
		pWindow.draw(textePrixDeVente);

		if(manager->getTourSelectionnee()->isTourAttaque())
		{
			ostringstream stringDommagesTour;
			stringDommagesTour << manager->getTourSelectionnee()->getDommages();
			texteDommagesTour.setString("Dommages : " + stringDommagesTour.str());

			pWindow.draw(texteDommagesTour);
		}


	}
}
