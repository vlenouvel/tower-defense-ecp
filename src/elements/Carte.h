/*
 * Carte.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef CARTE_H_
#define CARTE_H_


#include "ElementGraphique.h"

class Carte: public ElementGraphique {
public:
	Carte();
	virtual ~Carte();
	void desiner(sf::RenderWindow &pWindow);
	void dessiner();
	int imageCarte [40][30];
};

#endif /* CARTE_H_ */
