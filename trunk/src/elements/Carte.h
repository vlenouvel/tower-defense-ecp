/*
 * Carte.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef CARTE_H_
#define CARTE_H_

#define TAILLECARTEX 18
#define TAILLECARTEY 15

#include "ElementGraphique.h"
#include "Case.h"
#include "../ResourcesLoader.h"

class Carte: public ElementGraphique {
public:
	Carte();
	virtual ~Carte();
	void dessiner(sf::RenderWindow &pWindow);
	const static int imageCarteX = TAILLECARTEX;
	const static int imageCarteY = TAILLECARTEY;
	void nettoyerCarte();
	Case* imageCarte [imageCarteX][imageCarteY];
	Case * pCaseSortie;
};

#endif /* CARTE_H_ */
