/*
 * TourAttaque.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef TOURATTAQUE_H_
#define TOURATTAQUE_H_

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include "ComportementCiblage.h"
#include "Tour.h"
#include "../ResourceManager.h"

class TourAttaque: public Tour {
public:
	TourAttaque(int tPrix, Coordonnees tCoord);
	void virtual changerComportementCiblage(Personnage* (*fonctionCiblage)(std::vector<Personnage*>* ciblesPossibles));
	void agir();
	virtual ~TourAttaque();
	void dessiner(sf::RenderWindow &pWindow);

protected:
	// On utilise un pointeur vers une fonction statique pour le ciblage
	// On peut ainsi changer à la voler le ciblage de la tour
	// en changeant la fonction sur laquelle est le pointeur.
	void virtual attaque(Personnage* (*fonctionCiblage)(std::vector<Personnage*>* ciblesPossibles)) = 0;
	void trouverCibles();
	Personnage* (*pCibler)(std::vector<Personnage*>* ciblesPossibles);
	int attackDamage;
	int attackRange;
	std::vector<Personnage*> ciblesPossibles;
	sf::Time timeBetweenAttacks;
	sf::Clock clockFromLastAttack;
};

#endif /* TOURATTAQUE_H_ */
