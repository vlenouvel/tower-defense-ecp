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
#include "../ResourceManager.h"

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
	sf::Text texteNiveauTour;
	sf::Texture textureLevelUpBouton;
	sf::Sprite spriteLevelUpBouton;

};

#endif /* TABLEAUDEBORD_H_ */
