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
#include <iostream>

class Projectile: public ElementGraphique, public ElementJeu {
public:
	Projectile(Coordonnees tCoord, Personnage* tCible, int tDommages);
	virtual ~Projectile();
	virtual void dessiner(sf::RenderWindow &pWindow) = 0;
	virtual void agir();
	void avancer();

protected:
	virtual void toucherEnnemi() = 0;
	int dommages;
	int vitesse;
	Coordonnees coordonnees;
	Personnage *cible;
	sf::Texture textureProjectile;
	sf::Sprite spriteProjectile;
};

#endif /* PROJECTILE_H_ */
