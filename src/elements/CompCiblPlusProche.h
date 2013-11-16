/*
 * CompCiblPlusProche.h
 *
 *  TowerDefense ECP
 *       
 */

//Ce comportement doit permettre de cibler la cible qui est la plus proche de l'objectif.

#ifndef COMPCIBLPLUSPROCHE_H_
#define COMPCIBLPLUSPROCHE_H_

#include "ComportementCiblage.h"

class CompCiblPlusProche: public ComportementCiblage {
public:
	CompCiblPlusProche();
	virtual ~CompCiblPlusProche();
	static Personnage* cibler(std::vector<Personnage*>* ciblesPossibles);
};

#endif /* COMPCIBLPLUSPROCHE_H_ */
