/*
 * App.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef APP_H_
#define APP_H_
#include "elements/Menu.h"
#include "elements/Carte.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "etats/Etat.h"
#include "etats/EtatJeu.h"
#include "etats/EtatMenu.h"
#include "ResourceManager.h"
#include "elements/TourAttaqueBasique.h"
#include "elements/Coordonnees.h"

class App {
public:
	bool running;
	long double test;
	sf::Font font;
	sf::Text text5;
	App();
	void jouer();
	void boucle();
	void render();
	void update();
	void gererEvents();
	virtual ~App();
	void changerEtat(Etat *pNouvelEtat);


private:
	sf::RenderWindow window;
	Etat *pEtatActuel;
	sf::Clock horloge2;
};

#endif /* APP_H_ */
