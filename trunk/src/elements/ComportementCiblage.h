/*
 * ComportementCiblage.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef COMPORTEMENTCIBLAGE_H_
#define COMPORTEMENTCIBLAGE_H_

#include "Personnage.h"
#include "../ResourceManager.h"
#include <vector>
#include "math.h"
#include <iostream>


class ComportementCiblage {
public:
	ComportementCiblage();
	virtual ~ComportementCiblage();
	static Personnage* ciblerPlusProche(std::vector<Personnage*> ciblesPossibles);
	static Personnage* ciblerPlusFaible(std::vector<Personnage*> ciblesPossibles);
	static Personnage* ciblerZone(std::vector<Personnage*> ciblesPossibles);
	static Personnage* ciblerPremier(std::vector<Personnage*> ciblesPossibles);
};

#endif /* COMPORTEMENTCIBLAGE_H_ */
