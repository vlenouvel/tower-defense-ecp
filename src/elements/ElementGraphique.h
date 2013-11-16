/*
 * ElementGraphique.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef ELEMENTGRAPHIQUE_H_
#define ELEMENTGRAPHIQUE_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../ResourcesLoader.h"

class ElementGraphique {
public:
	ElementGraphique();
	void virtual dessiner(sf::RenderWindow &pWindow)=0;
	virtual ~ElementGraphique();
};

#endif /* ELEMENTGRAPHIQUE_H_ */
