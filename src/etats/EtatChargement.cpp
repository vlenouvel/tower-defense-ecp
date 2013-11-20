/*
 * EtatChargement.cpp
 *
 *  Created on: 18 nov. 2013
 *      Author: Vincent Lenouvel
 */

#include "EtatChargement.h"

EtatChargement::EtatChargement(App *tApp) : Etat(tApp)
{
	pApp = tApp;
	etape = RIEN;
	keepLoading = true;
	fontLoading.loadFromFile("resources/polices/Capture it.ttf");
	textLoading.setCharacterSize(48);
	textLoading.setFont(fontLoading);
	textLoading.setColor(sf::Color::White);
	textLoading.setStyle(sf::Text::Bold);
	textLoading.setPosition(220,250);
	textLoading.setString("Chargement...");
	clockLoading.restart();
	tempsMinimum = sf::seconds(1);
}

void EtatChargement::handleEvent(sf::Event event)
{
	if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
	{
		keepLoading = false;
	}
}

void EtatChargement::dessiner(sf::RenderWindow &pWindow)
{
	if(!keepLoading)
	{
		pWindow.close();
	} else {
		pWindow.draw(textLoading);
	}
}

void EtatChargement::agir()
{
	if(keepLoading)
	{
		ResourcesLoader *pLoader = ResourcesLoader::getInstance();
		switch(etape)
		{
		case RIEN:
			pLoader->ChargerPolices();
			etape = POLICES;
			break;
		case POLICES:
			pLoader->ChargerTextures();
			etape = TEXTURES;
			break;
		case TEXTURES:
			pLoader->ChargerSons();
			etape = SONS;
			break;
		case SONS:
			if(clockLoading.getElapsedTime() >= tempsMinimum)
			{
				Etat *pNouvelEtat = new EtatMenu(pApp);
				pApp->changerEtat(pNouvelEtat);
			}
			break;
		}
	}

}


EtatChargement::~EtatChargement() {
	// TODO Auto-generated destructor stub
}

