/*
 * Personnage.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include "Coordonnees.h"
#include "ElementGraphique.h"
#include "ElementJeu.h"
#include "../ResourceManager.h"
#include "Projectile.h"
#include "Case.h"
#include <iostream>
#include <exception>
#include <map>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <utility>

class Personnage: public ElementGraphique, public ElementJeu {
public:
	Personnage(int tVie, int tVitesse, int tArmure, Coordonnees tCoord);
	virtual ~Personnage();

	void agir();
	void avancer();
	void mourir();
	void perdrePV(int degat);
	void dessiner(sf::RenderWindow &pWindow);
	int getVie();
	Coordonnees getCoordonnees();
	Coordonnees coordonnees;

	//Pathfinding
	bool trouverChemin(Carte * pCarte);
	void ecrireChemin(Carte * pCarte);
protected:
	int vie;
	int vitesse;
	int armure;
private:
	sf::Texture texturePersonnage;
	sf::Sprite spritePersonnage;

	//Pathfinding
	vector<Case *> chemin;
	vector<Case *>::iterator cheminIterator;
	
};

#endif /* PERSONNAGE_H_ */
