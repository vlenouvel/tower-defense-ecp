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
	void dessiner(sf::RenderWindow &pWindow);
	int imageCarte [40][30];
private:
	sf::Texture textureCarte;
	sf::Sprite spriteCarte;
};

#endif /* CARTE_H_ */
