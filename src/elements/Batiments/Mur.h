/*
 * Mur.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef MUR_H_
#define MUR_H_

#include "../Batiment.h"
#include "../../ResourceManager.h"

class Mur: public Batiment {
public:
	Mur(Coordonnees tCoord);
	virtual ~Mur();
	void dessiner(sf::RenderWindow &pWindow);
	void agir();
	bool isTour();

private:
	sf::Texture textureMur;
	sf::Sprite spriteMur;
};

#endif /* MUR_H_ */
