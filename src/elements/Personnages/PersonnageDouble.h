/*
 * PersonnageDouble.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef PERSONNAGEDOUBLE_H_
#define PERSONNAGEDOUBLE_H_

#include "../Personnage.h"

class PersonnageDouble: public Personnage{
public:
	PersonnageDouble(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord);
	virtual ~PersonnageDouble();
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

#endif /* PERSONNAGEDOUBLE_H_ */