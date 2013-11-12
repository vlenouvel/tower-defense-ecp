/*
 * Personnage.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include "Coordonnees.h"
#include "ElementGraphique.h"
#include "ElementJeu.h"

class Personnage: public ElementGraphique, public ElementJeu {
public:
	Personnage(int tVie, int tVitesse, int tArmure, Coordonnees tCoord);
	virtual ~Personnage();
	void agir();
	void avancer();
	void mourir();
	void perdrePV(int degat);
	void dessiner(sf::RenderWindow &pWindow);
	int getVie();
	Coordonnees getCoordonnees();

protected:
	int vie;
	int vitesse;
	int armure;
	Coordonnees coordonnees;
	//Pathfinding

};

#endif /* PERSONNAGE_H_ */
