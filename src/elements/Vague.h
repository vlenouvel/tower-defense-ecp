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

#include "../ResourceManager.h"
#include "GenerateurVague.h"
#include "ElementJeu.h"
#include "Personnage.h"
#include "Coordonnees.h"
#include <iostream>

class Vague: public ElementJeu {
public:
	Vague(int niveau);
	void agir();
	void genererPersonnage();
	virtual ~Vague();

private:
	int niveauType;
	int nombreType;
	int nombrePersoRestant;
	int type;
	sf::Clock horlogePop;
	sf::Time tempsEntrePop;
};

#endif /* VAGUE_H_ */
