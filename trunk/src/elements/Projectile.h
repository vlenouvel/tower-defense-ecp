/*
 * Projectile.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "ElementGraphique.h"
#include "ElementJeu.h"
#include "Personnage.h"
#include "Coordonnees.h"

class Projectile: public ElementGraphique, public ElementJeu {
public:
	Projectile(Coordonnees tCoord, Personnage* tCible, int dommages);
	virtual ~Projectile();
	void dessiner(sf::RenderWindow &pWindow);
	virtual void agir();
	void avancer();
	virtual void toucherEnnemi() = 0;

private:
	int dommages;
	int vitesse;
	Coordonnees coordonnees;
	Personnage *cible;
};

#endif /* PROJECTILE_H_ */
