/*
 * ElementJeu.h
 *
 *  TowerDefense ECP
 *       
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
