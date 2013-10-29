/*
 * ElementGraphique.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef ELEMENTGRAPHIQUE_H_
#define ELEMENTGRAPHIQUE_H_

class ElementGraphique {
public:
	ElementGraphique();
	void virtual dessiner() = 0;
	virtual ~ElementGraphique();
};

#endif /* ELEMENTGRAPHIQUE_H_ */
