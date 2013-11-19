/*
 * ProjectileBasique.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef PROJECTILEBASIQUE_H_
#define PROJECTILEBASIQUE_H_

#include "Projectile.h"
#include "../ResourceManager.h"

class ProjectileBasique: public Projectile {
public:
	ProjectileBasique(Coordonnees tCoord, Personnage* tCible, int tDommages);
	void toucherEnnemi();
	virtual ~ProjectileBasique();
	void dessiner(sf::RenderWindow & rWindow);
	void avancer();
};

#endif /* PROJECTILEBASIQUE_H_ */