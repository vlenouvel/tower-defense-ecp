/*
 * App.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "App.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

App::App() {
	pEtatActuel = new(EtatMenu)(this);
	running = true;
	test = 0;
	test2 = 0;
	window.create(sf::VideoMode(800, 600), "Tower Defense");
}


void App::jouer() {
	bool AppEnCours;
	sf::Clock horloge;
	sf::Time framestartTime;
	sf::Time difference;
	sf::Time tempsLegal;
	sf::Time hibernation;
	const int imagesParSeconde = 1;
	sf::Int32 tempsSecret = 10;
	tempsLegal = sf::milliseconds(tempsSecret);
	// 1.f/(float)imagesParSeconde
	sf::Music music;
	music.openFromFile("resources/sons/musicTest.ogg");
	music.play();

	AppEnCours = true;
	
	// lance l'horloge
	horloge.restart();

	
	// boucle de jeu
	while (AppEnCours) {
		framestartTime = horloge.getElapsedTime();
		// la boucle en soi
		boucle();
		//fin de la boucle de jeu
		difference = horloge.getElapsedTime() - framestartTime;

		if (difference < tempsLegal){
			hibernation = tempsLegal - difference;
			sf::sleep(hibernation);
		}
		sf::Int32 i = horloge2.restart().asMilliseconds();
		test2 = test*1000 / i;
		test = 0;
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
	sf::RenderWindow &pWindow = window;

	window.clear();

	pEtatActuel->dessiner(pWindow);
	sf::Font font;
	font.loadFromFile("resources/polices/Capture it.ttf");
	sf::Text text5;
	text5.setFont(font);
	ostringstream ss;
	ss << test2;
	cout << test2 << endl;
	text5.setString(ss.str());
	test++;
	text5.setCharacterSize(48);
	text5.setColor(sf::Color::White);
	text5.setStyle(sf::Text::Bold);
	text5.setPosition(20,20);
	window.draw(text5);
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

