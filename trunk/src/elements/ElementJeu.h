/*
 * ElementJeu.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef ELEMENTJEU_H_
#define ELEMENTJEU_H_

class ElementJeu {
public:
	ElementJeu();
	void virtual agir() = 0;
	virtual ~ElementJeu();
};

#endif /* ELEMENTJEU_H_ */
