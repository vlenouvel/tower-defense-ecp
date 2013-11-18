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
	Batiment(Coordonnees tCoord);
	virtual ~Batiment();
	virtual bool verifierAchat();
	void dessiner(sf::RenderWindow &pWindow);
	Coordonnees coordonnees;
	virtual int getPrix();
	Coordonnees getCoordonnees();
protected:
	int prix;
	
};

#endif /* BATIMENT_H_ */
