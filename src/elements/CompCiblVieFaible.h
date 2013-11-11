/*
 * CompCiblVieFaible.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef COMPCIBLVIEFAIBLE_H_
#define COMPCIBLVIEFAIBLE_H_

#include "ComportementCiblage.h"

class CompCiblVieFaible: public ComportementCiblage {
public:
	CompCiblVieFaible();
	virtual ~CompCiblVieFaible();
	static Personnage* cibler(std::vector<Personnage*> ciblesPossibles);
};

#endif /* COMPCIBLVIEFAIBLE_H_ */
