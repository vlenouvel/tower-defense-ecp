/*
 * EtatJeu.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "EtatJeu.h"

EtatJeu::EtatJeu(App *tApp) : Etat(tApp) {
	// TODO Auto-generated constructor stub

}

void EtatJeu::dessiner(sf::RenderWindow &pWindow){
	Carte carte;
	carte.dessiner(pWindow);
}

void EtatJeu::handleEvent(sf::Event event)
{

}

EtatJeu::~EtatJeu() {
	// TODO Auto-generated destructor stub
}

