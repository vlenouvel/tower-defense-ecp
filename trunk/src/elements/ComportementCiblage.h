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

// Classe qui sert juste d'interface pour forcer l'implementation
// de la methode cibler dans les differents comportements de ciblage
class ComportementCiblage {
public:
	ComportementCiblage();
	virtual ~ComportementCiblage();
};

#endif /* COMPORTEMENTCIBLAGE_H_ */
