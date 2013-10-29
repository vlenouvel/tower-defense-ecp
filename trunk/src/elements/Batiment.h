/*
 * Batiment.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef BATIMENT_H_
#define BATIMENT_H_

#include "ElementGraphique.h"
#include "ElementJeu.h"

class Batiment: public ElementGraphique, public ElementJeu {
public:
	Batiment();
	virtual ~Batiment();

protected:
	int prix;
};

#endif /* BATIMENT_H_ */
