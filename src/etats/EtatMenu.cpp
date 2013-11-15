/*
 * EtatMenu.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "EtatMenu.h"

EtatMenu::EtatMenu(App* tApp) : Etat(tApp) {
	ResourceManager* manager = ResourceManager::getInstance();
	Menu* pMenu = new Menu();
	manager->addMenu(pMenu);
	menu = manager->getMenu();
}

void EtatMenu::handleEvent(sf::Event event)
{
	if ((event.type == sf::Event::MouseButtonPressed)) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			if ((event.mouseButton.x > 150) && (event.mouseButton.x < 650)
					&& (event.mouseButton.y > 100)
					&& (event.mouseButton.y < 150)) {
				Etat *pNouvelEtat = new(EtatJeu)(pApp);
				pApp->changerEtat(pNouvelEtat);
			}
		}
	}
}

void EtatMenu::dessiner(sf::RenderWindow &pWindow)
{

	menu->dessiner(pWindow);
}
EtatMenu::~EtatMenu() {
	// TODO Auto-generated destructor stub
}

