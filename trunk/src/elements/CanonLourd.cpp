/*
 * CanonLourd.cpp
 *
 *  Created on: 15 nov. 2013
 *      Author: Vincent Carrier
 */

#include "CanonLourd.h"
#include <iostream>

CanonLourd::CanonLourd(int tPrix, Coordonnees tCoord, int tNiveau) : TourAttaque(tPrix, tCoord, tNiveau) {
	textureCanonLourd.loadFromFile("resources/textures/textureCanonLourd.jpg");
	spriteCanonLourd.setTexture(textureCanonLourd);
	spriteCanonLourd.setScale(0.5,0.5);
	spriteCanonLourd.setPosition(tCoord.posX,tCoord.posY);
}

void CanonLourd::attaque(void (*fonctionCiblage)())
{

}

CanonLourd::~CanonLourd() {
	// TODO Auto-generated destructor stub
}

void CanonLourd::dessiner(sf::RenderWindow & rWindow){
	rWindow.draw(spriteCanonLourd);
}