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

class Projectile: public ElementGraphique, public ElementJeu {
public:
	Projectile();
	virtual ~Projectile();

private:
	Coordonnees coordonnees;
};

#endif /* PROJECTILE_H_ */
