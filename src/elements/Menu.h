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
private:
	sf::Font font;
	sf::Text text1;
	sf::Text text2;
	sf::Text text3;
};

#endif /* MENU_H_ */
