/*
 * PersonnageGenerateur.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef PERSONNAGEGENERATEUR_H_
#define PERSONNAGEGENERATEUR_H_

#include "../Personnage.h"

class PersonnageGenerateur: public Personnage{
public:
	PersonnageGenerateur(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord);
	virtual ~PersonnageGenerateur();
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
	int compteurCreation;
};

#endif /* PERSONNAGEGENERATEUR_H_ */