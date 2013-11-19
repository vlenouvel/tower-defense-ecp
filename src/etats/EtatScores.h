/*
 * EtatScores.h
 *
 *  Created on: 19 nov. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef ETATSCORES_H_
#define ETATSCORES_H_

#include "Etat.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "EtatMenu.h"

class EtatScores: public Etat {
public:
	EtatScores(App *tApp);
	void handleEvent(sf::Event event);
	void dessiner(sf::RenderWindow &pWindow);
	void agir();
	virtual ~EtatScores();

private:
	int meilleursScores[3];
	void lireMeilleursScores();
	sf::Text text;
	sf::Font font;
};

#endif /* ETATSCORES_H_ */
