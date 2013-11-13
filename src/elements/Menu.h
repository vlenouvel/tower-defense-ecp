/*
 * Menu.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef MENU_H_
#define MENU_H_

#include "ElementGraphique.h"

class Menu: public ElementGraphique {
public:
	Menu();
	virtual ~Menu();
	void dessiner(sf::RenderWindow &pWindow);
};

#endif /* MENU_H_ */