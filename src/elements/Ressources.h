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
	Ressources(Etat* pEtat);
	virtual ~Ressources();
	void dessiner(sf::RenderWindow &pWindow);
	double ressources;
	int getArgent();
	void perdreArgent(int montant);
	void gagnerArgent(int montant);
	int getVie();
	void perdreVie();
	int getScore();
	void augmenterScore(int nbPoint);

private:
	sf::Texture textureRessources;
	sf::Sprite spriteRessources;
	sf::Text texteRessources;
	sf::Font font;

	int argent;
	int vie;
	int score;

	Etat* pEtat;
};

#endif /* RESSOURCES_H_ */
