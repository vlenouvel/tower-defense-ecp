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

#include "Coordonnees.h"

class Projectile: public ElementGraphique, public ElementJeu {
public:
	Projectile(Coordonnees tCoord);
	virtual ~Projectile();

private:
	Coordonnees coordonnees;
};

#endif /* PROJECTILE_H_ */
