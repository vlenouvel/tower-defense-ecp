/*
 * App.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "App.h"
#include <iostream>

using namespace std;

App::App() {
	etat = 0;
	running = true;
	window.create(sf::VideoMode(800, 600), "Tower Defense");
	
}


bool App::isRunning() {
	if (window.isOpen() == true)
		return true;
	else
		return false;
}

void App::boucle() {
	App::gererEvents();
	App::update();
	App::render();
}

void App::gererEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		if ((event.type == sf::Event::MouseButtonPressed) && (etat == 0)) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				if ((event.mouseButton.x > 150) && (event.mouseButton.x < 650)
						&& (event.mouseButton.y > 100)
						&& (event.mouseButton.y < 150)) {
					etat = 1;
				}
			}
		}

	}
}

void App::update() {

}

void App::render() {
	sf::RenderWindow &pWindow = window;

	Carte carte;
	Menu menu;

    window.clear();

    if (etat == 0)
		menu.dessiner(pWindow);
	if (etat == 1)
		carte.dessiner(pWindow);

	window.display();
}

App::~App() {
	// TODO Auto-generated destructor stub
}

