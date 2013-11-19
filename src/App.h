/*
 * App.h
 *
 *  TowerDefense ECP
 *       
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
#include "etats/EtatMort.h"
#include "etats/EtatScores.h"
#include "etats/EtatChargement.h"
#include "ResourceManager.h"
#include "elements/Coordonnees.h"

class App {
public:
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
	long double test;
	Etat *pEtatActuel;
	sf::Font font;
	sf::Text texteFPS;
	sf::RenderWindow window;
};

#endif /* APP_H_ */
