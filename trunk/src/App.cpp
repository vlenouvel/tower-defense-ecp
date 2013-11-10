/*
 * App.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "App.h"

App::App() {
	etat = 0;

}

void App::init()
{
	sf::Music music;
	music.openFromFile("tower-defense-ecp/src/elements/musiquesEtBruits/musicTest.ogg");
	music.play();

	Menu menu;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Tower Defense");
	sf::RenderWindow &pWindow = window;

	menu.dessiner(pWindow);

	Carte carte;

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
			if ((event.type == sf::Event::MouseButtonPressed)&&(etat == 0)){
				if (event.mouseButton.button == sf::Mouse::Left){
					if ((event.mouseButton.x > 150)&&(event.mouseButton.x < 650)&&(event.mouseButton.y > 100)&&(event.mouseButton.y < 150)){
						etat = 1;
					}
				}
			}
		}
		pWindow.clear();
		if (etat == 0)
			menu.dessiner(pWindow);
		if (etat == 1)
			carte.dessiner(pWindow);
		window.display();
	}

}

App::~App() {
	// TODO Auto-generated destructor stub
}

