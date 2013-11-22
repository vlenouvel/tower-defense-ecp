/*
 * PersonnageVolant.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef PERSONNAGEVOLANT_H_
#define PERSONNAGEVOLANT_H_

#include "../Personnage.h"

class PersonnageVolant: public Personnage{
public:
	PersonnageVolant(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord);
	virtual ~PersonnageVolant();
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

#endif /* PERSONNAGEVOLANT_H_ */