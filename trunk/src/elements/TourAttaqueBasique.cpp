/*
 * TourAttaqueBasique.cpp
 *
 *  Created on: 13 nov. 2013
 *      Author: Vincent Lenouvel
 */

#include "TourAttaqueBasique.h"
#include <iostream>

TourAttaqueBasique::TourAttaqueBasique(int tPrix, Coordonnees tCoord, int tNiveau) : TourAttaque(tPrix, tCoord, tNiveau) {
	textureTourAttaqueBasique.loadFromFile("resources/textures/textureTourAttaqueBasique.jpg");
	spriteTourAttaqueBasique.setTexture(textureTourAttaqueBasique);
	spriteTourAttaqueBasique.setScale(0.5,0.5);
	spriteTourAttaqueBasique.setPosition(tCoord.posX,tCoord.posY);
}

void TourAttaqueBasique::attaque(void (*fonctionCiblage)())
{

}

TourAttaqueBasique::~TourAttaqueBasique() {
	// TODO Auto-generated destructor stub
}

void TourAttaqueBasique::dessiner(sf::RenderWindow & rWindow){
	rWindow.draw(spriteTourAttaqueBasique);
}

