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
	pEtatActuel = new(EtatMenu)(this);
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
		else
		{
			pEtatActuel->handleEvent(event);
		}

	}
}

void App::update() {

}

void App::render() {
	sf::RenderWindow &pWindow = window;

	window.clear();

	pEtatActuel->dessiner(pWindow);

	window.display();
}

void App::changerEtat(Etat *pNouvelEtat)
{
	delete pEtatActuel;
	pEtatActuel = pNouvelEtat;
}

App::~App() {
	// TODO Auto-generated destructor stub
}

