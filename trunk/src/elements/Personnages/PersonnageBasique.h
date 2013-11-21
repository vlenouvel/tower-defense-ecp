/*
 * PersonnageBasique.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef PERSONNAGEBASIQUE_H_
#define PERSONNAGEBASIQUE_H_

#include "../Personnage.h"

class PersonnageBasique: public Personnage{
public:
	PersonnageBasique(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord);
	virtual ~PersonnageBasique();
	void agir();
	void avancer();
	void mourir();
	void perdrePV(int degat);
	void dessiner(sf::RenderWindow &pWindow);
	int  getVie();
	void arriver();
	Coordonnees getCoordonnees();
	bool trouverChemin(Carte * pCarte);
	void ecrireChemin(Carte * pCarte);
};

#endif /* PERSONNAGEBASIQUE_H_ */