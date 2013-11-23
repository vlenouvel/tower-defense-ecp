/*
 * PersonnageAccelerant.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef PERSONNAGEACCELERANT_H_
#define PERSONNAGEACCELERANT_H_

#include "../Personnage.h"

class PersonnageAccelerant: public Personnage{
public:
	PersonnageAccelerant(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord);
	virtual ~PersonnageAccelerant();
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
	int vieDebut;
	int vitesseDebut;
};

#endif /* PERSONNAGEACCELERANT_H_ */