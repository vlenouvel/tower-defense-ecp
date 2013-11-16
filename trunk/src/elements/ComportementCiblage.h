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

// Classe qui sert juste d'interface pour forcer l'implementation
// de la methode cibler dans les differents comportements de ciblage
class ComportementCiblage {
public:
	ComportementCiblage();
	virtual ~ComportementCiblage();
	static Personnage* ciblerPlusProche(std::vector<Personnage*> ciblesPossibles);
	static Personnage* ciblerPlusFaible(std::vector<Personnage*> ciblesPossibles);
	static Personnage* ciblerZone(std::vector<Personnage*> ciblesPossibles);
};

#endif /* COMPORTEMENTCIBLAGE_H_ */
