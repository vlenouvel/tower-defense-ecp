/*
 * Ressources.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "Ressources.h"

Ressources::Ressources() {
	textureResources.loadFromFile("resources/textures/champDeBataille.jpg");
	spriteResources.setTexture(textureResources);
	spriteResources.setScale(1,1);
	spriteResources.setPosition(700,0);
	Resources = 0;

}

Ressources::~Ressources() {
	// TODO Auto-generated destructor stub
}

void Ressources::dessiner(sf::RenderWindow &pWindow){
	// TO DO
}

