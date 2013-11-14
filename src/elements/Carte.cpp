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
	textureCarte.loadFromFile("resources/textures/champDeBataille.jpg");
	spriteCarte.setTexture(textureCarte);
	spriteCarte.setScale(0.88,0.88);

}

Carte::~Carte() {
	// TODO Auto-generated destructor stub
}

void Carte::dessiner(sf::RenderWindow &pWindow){

	pWindow.draw(spriteCarte);
}
