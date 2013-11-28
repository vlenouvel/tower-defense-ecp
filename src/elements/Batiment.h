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
#include "../ConfigManager.h"

class Batiment: public ElementGraphique, public ElementJeu {
public:
	Batiment(Coordonnees tCoord);
	virtual ~Batiment();
	virtual bool verifierAchat();
	void dessiner(sf::RenderWindow &pWindow)=0;
	virtual int getPrix();
	Coordonnees getCoordonnees();
	void virtual vendreBatiment();
	virtual bool isTour() = 0;

protected:
	int prix;
	Coordonnees coordonnees;
	
};

#endif /* BATIMENT_H_ */
