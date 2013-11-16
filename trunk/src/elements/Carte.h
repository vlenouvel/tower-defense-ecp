/*
 * Carte.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef CARTE_H_
#define CARTE_H_


#include "ElementGraphique.h"
#include "Case.h"

class Carte: public ElementGraphique {
public:
	Carte();
	virtual ~Carte();
	void dessiner(sf::RenderWindow &pWindow);
	Case* imageCarte [20][15];
	Case * pCaseSortie;
private:
	sf::Texture textureCarte;
	sf::Sprite spriteCarte;
};

#endif /* CARTE_H_ */
