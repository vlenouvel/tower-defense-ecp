/*
 * EtatMenu.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "EtatMenu.h"

EtatMenu::EtatMenu(App* tApp) : Etat(tApp) {
	menu = new Menu();
}

void EtatMenu::handleEvent(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			if ((event.mouseButton.x > 150) && (event.mouseButton.x < 650)
					&& (event.mouseButton.y > 100)
					&& (event.mouseButton.y < 150)) {
				Etat *pNouvelEtat = new EtatJeu(pApp);
				pApp->changerEtat(pNouvelEtat);
			} else if((event.mouseButton.x > 150) && (event.mouseButton.x < 650)
					&& (event.mouseButton.y > 250)
					&& (event.mouseButton.y < 300))
			{
				Etat *pNouvelEtat = new EtatScores(pApp);
				pApp->changerEtat(pNouvelEtat);
			}
			else if((event.mouseButton.x > 300) && (event.mouseButton.x < 650)
					&& (event.mouseButton.y > 400)
					&& (event.mouseButton.y < 450))
			{
				Etat *pNouvelEtat = new EtatPropos(pApp);
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
void EtatMenu::update(){
	// TODO ou rien
}

