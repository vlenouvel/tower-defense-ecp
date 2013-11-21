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

	void virtual agir()=0;
	void virtual avancer()=0;
	void virtual mourir()=0;
	void virtual perdrePV(int degat)=0;
	void virtual dessiner(sf::RenderWindow &pWindow)=0;
	int  virtual getVie()=0;
	void virtual arriver()=0;
	Coordonnees virtual getCoordonnees()=0;
	bool virtual trouverChemin(Carte * pCarte)=0;
	void virtual ecrireChemin(Carte * pCarte)=0;

	void mourirPersonnage();
	void agirPersonnage();
	void avancerPersonnage();
	void perdrePVPersonnage(int degat);
	void dessinerPersonnage(sf::RenderWindow &pWindow);
	int getViePersonnage();
	void arriverPersonnage();
	Coordonnees getCoordonneesPersonnage();
	Coordonnees coordonnees;
	int pourcentageVitesseMalus;
	//Pathfinding
	bool trouverCheminPersonnage(Carte * pCarte);
	void ecrireCheminPersonnage(Carte * pCarte);
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
