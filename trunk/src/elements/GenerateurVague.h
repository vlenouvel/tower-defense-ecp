/*
 * GenerateurVague.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef GENERATEURVAGUE_H_
#define GENERATEURVAGUE_H_

#include "ElementJeu.h"
#include "ElementGraphique.h"

#include <SFML/Window.hpp>
#include "Vague.h"
#include <iostream>


class GenerateurVague : public ElementJeu{
public:
	GenerateurVague();
	virtual ~GenerateurVague();
	void agir();
	void genererVague();
	int niveau;
private:
	sf::Time tempsEntreVague;
	sf::Clock horlogeVague;

	sf::Text texteNiveau;
	sf::Font font;
};

#endif /* GENERATEURVAGUE_H_ */
