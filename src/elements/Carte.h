/*
 * Carte.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef CARTE_H_
#define CARTE_H_


#include "ElementGraphique.h"
#include "Case.h"

class Carte: public ElementGraphique {
public:
	Carte();
	virtual ~Carte();
	void dessiner(sf::RenderWindow &pWindow);
	const static int imageCarteX = 20;
	const static int imageCarteY = 15;
	Case* imageCarte [imageCarteX][imageCarteY];
	Case * pCaseSortie;
	void nettoyerCarte();
private:
	sf::Texture textureCarte;
	sf::Sprite spriteCarte;
};

#endif /* CARTE_H_ */
