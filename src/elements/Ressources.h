/*
 * Ressources.h
 *
 *  TowerDefense ECP
 *      Author: Vincent Lenouvel
 */

#ifndef RESSOURCES_H_
#define RESSOURCES_H_

#include "ElementGraphique.h"
#include "../etats/Etat.h"
#include <cmath>

class Ressources: public ElementGraphique {
public:
	Ressources();
	virtual ~Ressources();
	void dessiner(sf::RenderWindow &pWindow);

	int getVie();
	void perdreVie();

	int getArgent();
	void perdreArgent(int montant);
	void gagnerArgent(int montant);

	int getScore();
	void augmenterScore(int nbPoint);

	void setVagues(int nbVagues);

private:
	sf::Text texteRessources;
	sf::Font font;

	int argent;
	int vie;
	int score;
	int nombreVagues;
};

#endif /* RESSOURCES_H_ */
