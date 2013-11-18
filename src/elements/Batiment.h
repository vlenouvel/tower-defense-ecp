/*
 * Batiment.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef BATIMENT_H_
#define BATIMENT_H_

#include "Coordonnees.h"

#include "ElementGraphique.h"
#include "ElementJeu.h"

class Batiment: public ElementGraphique, public ElementJeu {
public:
	Batiment(int tPrix, Coordonnees tCoord);
	virtual ~Batiment();
	void dessiner(sf::RenderWindow &pWindow);
	Coordonnees coordonnees;
	static bool verifierAchat(int prixBat);
	Coordonnees getCoordonnees();
protected:
	int prix;
	
};

#endif /* BATIMENT_H_ */
