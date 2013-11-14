/*
 * App.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "App.h"
#include <iostream>
#include <string>

using namespace std;

App::App() {
	pEtatActuel = new(EtatMenu)(this);
	running = true;
	test = 0;
	font.loadFromFile("resources/polices/Capture it.ttf");
	text5.setFont(font);
	text5.setCharacterSize(48);
	text5.setColor(sf::Color::White);
	text5.setStyle(sf::Text::Bold);
	text5.setPosition(20,20);
	window.create(sf::VideoMode(800, 600), "Tower Defense");
}
App::~App() {
	// TODO Auto-generated destructor stub
}


void App::jouer() {
	bool AppEnCours;
	sf::Clock horloge;
	sf::Time framestartTime;
	sf::Time difference;
	sf::Time tempsLegal;
	sf::Time hibernation;
	long double imagesParSeconde = 20;
	float tempsUneImage = 1.f/imagesParSeconde;
	tempsLegal = sf::seconds(tempsUneImage);
	sf::Music music;
	music.openFromFile("resources/sons/musicTest2.ogg");
	music.play();

	
	// lance l'horloge
	horloge.restart();

	
	// boucle de jeu
	while (window.isOpen()) {
		framestartTime = horloge.getElapsedTime();
		// la boucle en soi
		boucle();
		//fin de la boucle de jeu
		difference = horloge.getElapsedTime() - framestartTime;

		if (difference < tempsLegal){
			hibernation = tempsLegal - difference;
			sf::sleep(hibernation);
			test = imagesParSeconde;
		}
		else
			test = 1./difference.asSeconds();
	}
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
	sf::RenderWindow &rWindow = window;
	window.clear();
	Coordonnees coordonneesTest(10,10);
	TourAttaqueBasique tourTest(100,coordonneesTest,1);
	pEtatActuel->dessiner(rWindow);
	tourTest.dessiner(rWindow);
	text5.setString(to_string(test));

	window.draw(text5);
	window.display();
}

void App::changerEtat(Etat *pNouvelEtat)
{
	delete pEtatActuel;
	pEtatActuel = pNouvelEtat;
}

