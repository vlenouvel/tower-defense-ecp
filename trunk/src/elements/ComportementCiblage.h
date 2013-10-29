/*
 * ComportementCiblage.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef COMPORTEMENTCIBLAGE_H_
#define COMPORTEMENTCIBLAGE_H_

#include "Personnage.h"
#include <vector>

class ComportementCiblage {
public:
	ComportementCiblage();
	virtual ~ComportementCiblage();
	Personnage* cibler(std::vector<Personnage>* ciblesPossibles);
};

#endif /* COMPORTEMENTCIBLAGE_H_ */
