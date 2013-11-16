/*
 * Ressources.h
 *
 *  TowerDefense ECP
 *      Author: Vincent Lenouvel
 */

#ifndef RESSOURCES_H_
#define RESSOURCES_H_

#include "ElementGraphique.h"
#include <cmath>

class Ressources: public ElementGraphique {
public:
	Ressources();
	virtual ~Ressources();
	void dessiner(sf::RenderWindow &pWindow);
	double ressources;
	int getArgent();
	void perdreArgent(int montant);
	void gagnerArgent(int montant);
private:
	sf::Texture textureRessources;
	sf::Sprite spriteRessources;
	sf::Text texteRessources;
	sf::Font font;

	int argent;
};

#endif /* RESSOURCES_H_ */
