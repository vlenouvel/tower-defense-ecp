/*
 * Ressources.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef RESSOURCES_H_
#define RESSOURCES_H_

#include "ElementGraphique.h"
#include <cmath>

class Ressources: public ElementGraphique {
public:
	Ressources();
	virtual ~Ressources();
	void dessiner(sf::RenderWindow &pWindow);
	double ressources;
private:
	sf::Texture textureRessources;
	sf::Sprite spriteRessources;
	sf::Text texteRessources;
	sf::Font font;
};

#endif /* RESSOURCES_H_ */
