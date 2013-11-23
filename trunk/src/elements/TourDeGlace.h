/*
 * TourDeGlace.h
 *
 *  TowerDefense ECP
 *      
 */

#ifndef TOURDEGLACE_H_
#define TOURDEGLACE_H_

#include "TourAttaque.h"
#include "TirDeGlace.h"


class TourDeGlace: public TourAttaque {
public:
	TourDeGlace(Coordonnees tCoord);
	virtual ~TourDeGlace();
	void dessiner(sf::RenderWindow & rWindow);
	void actionSpeciale();

private:
	void attaque(Personnage* (*fonctionCiblage)(std::vector<Personnage*> ciblesPossibles));
	int rayonExplosion;
	sf::Sound sonTirTourGlace;
	sf::Sprite spriteTourDeGlace;
	sf::Sprite spriteEnvironementTourDeGlace;
	double rotation;
};

#endif /* TOURDEGLACE_H_ */