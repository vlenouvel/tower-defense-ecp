/*
 * Case.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef CASE_H_
#define CASE_H_

#include "ElementGraphique.h"
#include "ElementJeu.h"

class Case: public ElementGraphique, public ElementJeu {
public:
	Case();
	virtual ~Case();
};

#endif /* CASE_H_ */
