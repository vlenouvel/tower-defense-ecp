/*
 * TableauDeBord.h
 *
 *  TowerDefense ECP
 *      
 */

#ifndef TABLEAUDEBORD_H_
#define TABLEAUDEBORD_H_

#include "ElementGraphique.h"
#include <cmath>

class TableauDeBord: public ElementGraphique {
public:
	TableauDeBord();
	virtual ~TableauDeBord();
	void dessiner(sf::RenderWindow &pWindow);
private:
	sf::Texture textureTableauDeBord;
	sf::Sprite spriteTableauDeBord;
	sf::Text texteTableauDeBord;
	sf::Font font;
	sf::Texture textureCanonLourd;
	sf::Sprite spriteCanonLourd;
	sf::Texture textureTourAttaqueBasique;
	sf::Sprite spriteTourAttaqueBasique;
};

#endif /* TABLEAUDEBORD_H_ */