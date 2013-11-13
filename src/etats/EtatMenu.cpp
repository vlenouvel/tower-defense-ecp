/*
 * EtatMenu.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "EtatMenu.h"

EtatMenu::EtatMenu(App* tApp) : Etat(tApp) {

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
	Menu menu;
	menu.dessiner(pWindow);
}
EtatMenu::~EtatMenu() {
	// TODO Auto-generated destructor stub
}
