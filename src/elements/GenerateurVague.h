/*
 * GenerateurVague.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef GENERATEURVAGUE_H_
#define GENERATEURVAGUE_H_

#include "ElementJeu.h"
#include <SFML/Window.hpp>


class GenerateurVague: public ElementJeu {
public:
	GenerateurVague(sf::Time timeElapsed);
	virtual ~GenerateurVague();
	void genererVague(sf::Time timeElapsed);
private:
	sf::Time tempsDerniereVague;
	sf::Time tempsEntreVague;
	int niveau;
};

#endif /* GENERATEURVAGUE_H_ */
