/*
 * TableauDeBord.h
 *
 *  TowerDefense ECP
 *      
 */

#ifndef TABLEAUDEBORD_H_
#define TABLEAUDEBORD_H_

#include "ElementGraphique.h"
#include "../ResourceManager.h"
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include "Batiments/TourAttaque.h"

class TableauDeBord: public ElementGraphique {
public:
	TableauDeBord();
	virtual ~TableauDeBord();
	void dessiner(sf::RenderWindow &pWindow);
	enum typeBatiment {AUCUN, BASIQUE, CANON, EXPLOSIF, FROST, SUPPORT, MUR};
	void setSelectionBat(typeBatiment type);

private:
	sf::Sprite spriteTableauDeBord;
	sf::Text texteTableauDeBord;
	sf::Font font;
	sf::Sprite spriteCanonLourd;
	sf::Sprite spriteTourAttaqueBasique;
	sf::Sprite spriteTourDeGlace;
	sf::Sprite spriteMur;
	sf::Sprite spriteTourSupport;
	sf::Text texteNiveauTour;
	sf::Sprite spriteLevelUpBouton;
	sf::Text texteDommagesTour;
	sf::Sprite spriteSellBouton;
	sf::Text texteCoutAmelioration;
	sf::Text textePrixDeVente;
	sf::Sprite spriteTourSelectionnee;
	sf::Text texteComportementPremier;
	sf::Text texteComportementMoinsVie;
	sf::Text texteComportementZone;
	sf::Text texteComportementRandom;

	typeBatiment typeSelection;

};

#endif /* TABLEAUDEBORD_H_ */
