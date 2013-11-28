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
#include <exception>
#include <map>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <utility>

class Personnage: public ElementGraphique, public ElementJeu {
public:
	Personnage(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord);
	virtual ~Personnage();

	void virtual agir();
	void virtual avancer();
	void virtual mourir();
	void virtual perdrePV(int degat);
	void virtual dessiner(sf::RenderWindow &pWindow);
	int  virtual getVie();
	void virtual arriver();
	Coordonnees virtual getCoordonnees();
	bool virtual trouverChemin(Carte * pCarte);
	void virtual ecrireChemin(Carte * pCarte);
	int getPoucentageVitesseMalus();
	void setPourcentageVitesseMalus(int malus);
	bool virtual isVolant();

	//Pathfinding
	bool trouverCheminPersonnage(Carte * pCarte);
	void ecrireCheminPersonnage(Carte * pCarte);
	//Pathfinding
	std::vector<Case *> chemin;
	std::vector<Case *>::iterator cheminIterator;
protected:
	// ce booleen sert a savoir si le personnage est volant, c'est-a-dire s'il n'a pas a recalculer son chemin si une
	// nouvelle tour est cree
	int pourcentageVitesseMalus;
	Coordonnees coordonnees;
	int vie;
	int vieInitial;
	int vitesse;
	int armure;
	int gain;
	sf::RectangleShape barreDeVieVerte;
	sf::RectangleShape barreDeVieRouge;


	
};

#endif /* PERSONNAGE_H_ */
