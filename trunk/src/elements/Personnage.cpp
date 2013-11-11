/*
 * Personnage.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "Personnage.h"


Personnage::Personnage(int tVie, int tVitesse, int tArmure, Coordonnees tCoord) :
		vie(tVie), vitesse(tVitesse), armure(tArmure), coordonnees(tCoord)
{

}

void Personnage::agir()
{
	this->avancer();
}

void Personnage::avancer()
{

}

void Personnage::perdrePV(int degat)
{
	if(degat > armure){
		vie -= (degat - armure);
		if(vie <= 0)
		{
			this->mourir();
		}
	}
}

void Personnage::mourir()
{

}

Personnage::~Personnage() {
	// TODO Auto-generated destructor stub
}

void Personnage::dessiner(sf::RenderWindow &pWindow){
	// TO DO
}

int Personnage::getVie()
{
	return this->vie;
}
