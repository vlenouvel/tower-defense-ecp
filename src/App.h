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
#include "elements/CanonLourd.h"
#include "elements/Coordonnees.h"

class App {
public:
	bool running;
	long double test;
	sf::Font font;
	sf::Text texteFPS;
	App();
	void jouer();
	void boucle();
	void render();
	void update();
	void gererEvents();
	virtual ~App();
	void changerEtat(Etat *pNouvelEtat);
	sf::Clock horloge;


private:
	sf::RenderWindow window;
	Etat *pEtatActuel;
};

#endif /* APP_H_ */
