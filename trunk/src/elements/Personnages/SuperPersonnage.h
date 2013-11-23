/*
 * SuperPersonnage.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef SUPERPERSONNAGE_H_
#define SUPERPERSONNAGE_H_

#include "../Personnage.h"

class SuperPersonnage: public Personnage{
public:
	SuperPersonnage(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord);
	virtual ~SuperPersonnage();
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
};

#endif /* SUPERPERSONNAGE_H_ */