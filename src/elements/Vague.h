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
#include "Personnage.h"
#include "Coordonnees.h"

class Vague: public ElementJeu {
public:
	Vague(int niveau);
	void agir();
	void genererPersonnage(int nbPersonnage);
	virtual ~Vague();

private:
	int niveauType;
	const int nombreType = 1;
	sf::Clock horlogePop;
	sf::Time tempsEntrePop;
	Coordonnees coordonneesDepart;
};

#endif /* VAGUE_H_ */
