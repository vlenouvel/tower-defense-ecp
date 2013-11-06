/*
 * CompCiblZone.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef COMPCIBLZONE_H_
#define COMPCIBLZONE_H_

#include "ComportementCiblage.h"

class CompCiblZone: public ComportementCiblage {
public:
	CompCiblZone();
	virtual ~CompCiblZone();
	static Personnage* cibler(std::vector<Personnage>* ciblesPossibles);
};

#endif /* COMPCIBLZONE_H_ */
