/*
 * App.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "App.h"

App::App() {
	// TODO Auto-generated constructor stub

}

void App::init()
{
	Menu menu;
	bool debutJeu = menu.afficher();
	if (debutJeu == true){
		sf::RenderWindow window(sf::VideoMode(800, 600), "Tower Defense");
		sf::RenderWindow &pWindow = window;
		Carte carte;
		while (window.isOpen()){
			sf::Event event;
			while (window.pollEvent(event)){
				if (event.type == sf::Event::Closed)
					window.close();
				}
			window.clear();
			carte.desiner(pWindow);
			window.display();
		}
	}
}

App::~App() {
	// TODO Auto-generated destructor stub
}

