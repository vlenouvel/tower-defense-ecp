/*
 * Vague.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef VAGUE_H_
#define VAGUE_H_

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include "GenerateurVague.h"
#include "ElementJeu.h"

class Vague: public ElementJeu {
public:
	Vague();
	void agir();
	void genererPersonnage();
	virtual ~Vague();

private:
	sf::Clock horlogePop;
	sf::Time tempsEntrePop;
	GenerateurVague *pGenerateur;
};

#endif /* VAGUE_H_ */
