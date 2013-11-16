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
#include "Vague.h"
#include <iostream>


class GenerateurVague : public ElementJeu {
public:
	GenerateurVague();
	virtual ~GenerateurVague();
	void agir();
	void genererVague();
private:
	sf::Time tempsEntreVague;
	sf::Clock horlogeVague;
	int niveau;
};

#endif /* GENERATEURVAGUE_H_ */
