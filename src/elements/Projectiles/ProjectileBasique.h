/*
 * ProjectileBasique.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef PROJECTILEBASIQUE_H_
#define PROJECTILEBASIQUE_H_

#include "../Projectile.h"
#include "../../ResourceManager.h"

class ProjectileBasique: public Projectile {
public:
	ProjectileBasique(Coordonnees tCoord, Personnage* tCible, int tDommages);
	virtual ~ProjectileBasique();
	void dessiner(sf::RenderWindow & rWindow);
	void avancer();

private:
	void toucherEnnemi();
};

#endif /* PROJECTILEBASIQUE_H_ */
