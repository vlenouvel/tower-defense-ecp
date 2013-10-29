/*
 * Personnage.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include "ElementGraphique.h"
#include "ElementJeu.h"

class Personnage: public ElementGraphique, public ElementJeu {
public:
	Personnage();
	virtual ~Personnage();
};

#endif /* PERSONNAGE_H_ */
