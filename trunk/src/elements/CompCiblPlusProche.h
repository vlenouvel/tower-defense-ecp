/*
 * CompCiblPlusProche.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef COMPCIBLPLUSPROCHE_H_
#define COMPCIBLPLUSPROCHE_H_

#include "ComportementCiblage.h"

class CompCiblPlusProche: public ComportementCiblage {
public:
	CompCiblPlusProche();
	virtual ~CompCiblPlusProche();
	static Personnage* cibler(std::vector<Personnage>* ciblesPossibles);
};

#endif /* COMPCIBLPLUSPROCHE_H_ */