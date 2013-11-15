/*
 * TourAttaqueBasique.cpp
 *
 *  Created on: 13 nov. 2013
 *      Author: Vincent Lenouvel
 */

#include "TourAttaqueBasique.h"
#include <iostream>
#include <cmath>

TourAttaqueBasique::TourAttaqueBasique(int tPrix, Coordonnees tCoord, int tNiveau) : TourAttaque(tPrix, tCoord, tNiveau) {
	textureTourAttaqueBasique.loadFromFile("resources/textures/textureTourAttaqueBasique.jpg");
	spriteTourAttaqueBasique.setTexture(textureTourAttaqueBasique);
	spriteTourAttaqueBasique.setScale(0.5,0.5);
	spriteTourAttaqueBasique.setPosition((float)(tCoord.posX/40)*40,floor((float)(tCoord.posY/40))*40);
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

