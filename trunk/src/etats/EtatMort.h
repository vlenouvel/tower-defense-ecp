/*
 * EtatMort.h
 *
 *  Created on: 17 nov. 2013
 *      Author: francois
 */

#ifndef ETATMORT_H_
#define ETATMORT_H_

#include "Etat.h"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../etats/EtatMenu.h"
#include <sstream>
#include "../App.h"
#include <iostream>
#include <fstream>

class EtatMort : public Etat {
public:
	EtatMort(App* tApp);
	virtual ~EtatMort();
	void handleEvent(sf::Event event);
	void dessiner(sf::RenderWindow &pWindow);
	void update();

private:
	void clearAllElements();
	sf::Font font;
	sf::Text text1;
	sf::Text text2;
	sf::Text text3;
	sf::Text text4;

};

#endif /* ETATMORT_H_ */
