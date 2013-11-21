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

using namespace std;
class Personnage: public ElementGraphique, public ElementJeu {
public:
	Personnage(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord);
	virtual ~Personnage();

	void agir();
	void avancer();
	void mourir();
	void perdrePV(int degat);
	void dessiner(sf::RenderWindow &pWindow);
	int getVie();
	void arriver();
	Coordonnees getCoordonnees();
	Coordonnees coordonnees;
	int pourcentageVitesseMalus;
	//Pathfinding
	bool trouverChemin(Carte * pCarte);
	void ecrireChemin(Carte * pCarte);
	//Pathfinding
	vector<Case *> chemin;
	vector<Case *>::iterator cheminIterator;
protected:
	int vie;
	int vieInitial;
	int vitesse;
	int armure;
	int gain;
	sf::Texture texturePersonnage;
	sf::Sprite spritePersonnage;
	sf::RectangleShape barreDeVieVerte;
	sf::RectangleShape barreDeVieRouge;


	
};

#endif /* PERSONNAGE_H_ */
