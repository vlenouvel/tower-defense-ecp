/*
 * TourAttaqueBasique.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef TOURATTAQUEBASIQUE_H_
#define TOURATTAQUEBASIQUE_H_

#include "TourAttaque.h"
#include "ProjectileBasique.h"

class TourAttaqueBasique: public TourAttaque {
public:
	TourAttaqueBasique(int tPrix, Coordonnees tCoord);
	virtual ~TourAttaqueBasique();
	void dessiner(sf::RenderWindow & rWindow);

private:
	sf::Sound sonTirTourAttaqueBasique;
	void attaque(Personnage* (*fonctionCiblage)(std::vector<Personnage*> ciblesPossibles));
	sf::Texture textureTourAttaqueBasique;
	sf::Sprite spriteTourAttaqueBasique;
};

#endif /* TOURATTAQUEBASIQUE_H_ */
