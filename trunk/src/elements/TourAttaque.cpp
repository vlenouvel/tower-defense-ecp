/*
 * TourAttaque.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "TourAttaque.h"

TourAttaque::TourAttaque() {
	// TODO Auto-generated constructor stub

}

void TourAttaque::agir()
{
	//TODO : si temps avant attaque suivante atteint, attaque, sinon rien
	this->attaque();
}

void TourAttaque::attaque()
{
	// Calcul cibles possibles
	//std::vector<Personnage*>* pCiblesPossibles;
	//Personnage* pCible = compCibl.cibler(pCiblesPossibles);
}
TourAttaque::~TourAttaque() {
	// TODO Auto-generated destructor stub
}

