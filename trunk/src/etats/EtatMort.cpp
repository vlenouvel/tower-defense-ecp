/*
 * EtatMort.cpp
 *
 */

#include "EtatMort.h"

EtatMort::EtatMort(App* tApp) : Etat(tApp) {
	pApp = tApp;

	ResourceManager* manager = ResourceManager::getInstance();

	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();

	font = pResourcesLoader->police;
	text1.setFont(font);
	text1.setString("Vous avez perdu !");
	text1.setCharacterSize(48);
	text1.setColor(sf::Color::Red);
	text1.setStyle(sf::Text::Bold);
	text1.setPosition(150, 100);

	int score = manager->getRessources()->getScore();
	text2.setFont(font);
	text2.setString("Votre score est de : " + to_string(score));
	text2.setCharacterSize(32);
	text2.setColor(sf::Color::White);
	text2.setStyle(sf::Text::Bold);
	text2.setPosition(180, 250);

	text3.setFont(font);
	text3.setString("Cliquez pour revenir au menu");
	text3.setCharacterSize(24);
	text3.setColor(sf::Color::White);
	text3.setStyle(sf::Text::Bold);
	text3.setPosition(350,400);


}

void EtatMort::handleEvent(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			// Efface le Resource manager
			ResourceManager* manager = ResourceManager::getInstance();

			// manager->cartePointeur = 0;
			//manager->menuPointeur = 0;
			delete manager->ressourcesPointeur;
			manager->projectileConteneur.clear();
			manager->personnageConteneur.clear();
			manager->tourConteneur.clear();
			delete manager->vagueGenerateurPointeur;
			delete manager->vaguePointeur;

			Etat *pNouvelEtat = new(EtatMenu)(pApp);
			pApp->changerEtat(pNouvelEtat);

		}
	}
}

void EtatMort::dessiner(sf::RenderWindow &pWindow)
{
	pWindow.draw(text1);
	pWindow.draw(text2);
	pWindow.draw(text3);
}
EtatMort::~EtatMort() {
	// TODO Auto-generated destructor stub
}

