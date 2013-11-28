/*
 * ComportementCiblage.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef COMPORTEMENTCIBLAGE_H_
#define COMPORTEMENTCIBLAGE_H_

#include "Personnage.h"
#include "../ResourceManager.h"
#include <vector>
#include "math.h"
#include <stdlib.h>
#include "../ConfigManager.h"
#include <cassert>


class ComportementCiblage {
public:
	ComportementCiblage();
	virtual ~ComportementCiblage();
	static Personnage* ciblerPlusProche(std::vector<Personnage*> ciblesPossibles);
	static Personnage* ciblerPlusFaible(std::vector<Personnage*> ciblesPossibles);
	static Personnage* ciblerZone(std::vector<Personnage*> ciblesPossibles);
	static Personnage* ciblerRandom(std::vector<Personnage*> ciblesPossibles);
	enum Comportement {PlusFaible, PlusProche, Zone, Random};
};

#endif /* COMPORTEMENTCIBLAGE_H_ */
