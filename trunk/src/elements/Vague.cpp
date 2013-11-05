/*
 * Vague.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "Vague.h"

Vague::Vague() {
	// TODO Auto-generated constructor stub

}

void Vague::genererPersonnage()
{

}

void Vague::agir()
{
	sf::Time timeElapsed = horlogePop.getElapsedTime();
	if (timeElapsed > tempsEntrePop)
	{
		horlogePop.restart();
		genererPersonnage();
	}
}

Vague::~Vague() {
	// TODO Auto-generated destructor stub
}

