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

class TourAttaque: public Tour {
public:
	TourAttaque(int tPrix, Coordonnees tCoord, int tNiveau);
	void virtual changerComportementCiblage(void (*fonctionCiblage)());
	void agir();
	virtual ~TourAttaque();
	void dessiner(sf::RenderWindow &pWindow);

protected:
	// On utilise un pointeur vers une fonction statique pour le ciblage
	// On peut ainsi changer à la voler le ciblage de la tour
	// en changeant la fonction sur laquelle est le pointeur.
	void virtual attaque(void (*fonctionCiblage)()) = 0;
	void (*pCibler)();
	int attackDamage;
	int attackRange;
	sf::Time timeBetweenAttacks;
	sf::Clock clockFromLastAttack;
};

#endif /* TOURATTAQUE_H_ */
