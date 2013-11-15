/*
 * Ressources.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef RESSOURCES_H_
#define RESSOURCES_H_

#include "ElementGraphique.h"

class Ressources: public ElementGraphique {
public:
	Ressources();
	virtual ~Ressources();
	void dessiner(sf::RenderWindow &pWindow);
	int Resources;
private:
	sf::Texture textureResources;
	sf::Sprite spriteResources;
};

#endif /* RESSOURCES_H_ */
