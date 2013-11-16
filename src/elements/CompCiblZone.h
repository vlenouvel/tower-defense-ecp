/*
 * CompCiblZone.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef COMPCIBLZONE_H_
#define COMPCIBLZONE_H_

#include "ComportementCiblage.h"

class CompCiblZone: public ComportementCiblage {
public:
	CompCiblZone();
	virtual ~CompCiblZone();
	static Personnage* cibler(std::vector<Personnage*>* ciblesPossibles,std::vector<Personnage*>*touslespersonnages, float range);
};

#endif /* COMPCIBLZONE_H_ */
