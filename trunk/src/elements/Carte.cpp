/*
 * Carte.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "Carte.h"

Carte::Carte() {
	for (int i=0; i<40; i++){
		for (int j=0; j<30; j++){
			imageCarte[i][j] = 0;
		}
	}
	imageCarte[5][8] = 2;
}

Carte::~Carte() {
	// TODO Auto-generated destructor stub
}

void Carte::dessiner(sf::RenderWindow &pWindow){

	for (int i=0;i<40;i++){
		for(int j=0;j<30;j++){
			sf::RectangleShape rectangle(sf::Vector2f(18, 18));
			rectangle.setPosition(20*i,20*j);
			if (imageCarte[i][j] == 0)
				rectangle.setFillColor(sf::Color(50, 100, 50));
			else if (imageCarte[i][j] == 2)
				rectangle.setFillColor(sf::Color(100, 50, 50));
			pWindow.draw(rectangle);
		}
	}
}
