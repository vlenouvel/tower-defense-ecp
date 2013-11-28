/*
 * TourAttaqueBasique.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef TOURATTAQUEBASIQUE_H_
#define TOURATTAQUEBASIQUE_H_

#include "TourAttaque.h"
#include "../Projectiles/ProjectileBasique.h"

class TourAttaqueBasique: public TourAttaque {
public:
	TourAttaqueBasique(Coordonnees tCoord);
	virtual ~TourAttaqueBasique();
	void dessiner(sf::RenderWindow & rWindow);

private:
	sf::Sound sonTirTourAttaqueBasique;
	void attaque(Personnage* (*fonctionCiblage)(std::vector<Personnage*> ciblesPossibles));
};

#endif /* TOURATTAQUEBASIQUE_H_ */
