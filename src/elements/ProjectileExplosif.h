/*
 * ProjectileExplosif.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef PROJECTILEEXPLOSIF_H_
#define PROJECTILEEXPLOSIF_H_

#include "Projectile.h"
#include "../ResourceManager.h"
#include "math.h"
#include "../ResourcesLoader.h"

class ProjectileExplosif: public Projectile {
public:
	ProjectileExplosif(Coordonnees tCoord, Personnage* tCible, int tDommages, int tRayonExplosion);
	void toucherEnnemi();
	virtual ~ProjectileExplosif();
	void dessiner(sf::RenderWindow & rWindow);
	void avancer();
private:
	int rayonExplosion;
};

#endif /* PROJECTILEEXPLOSIF_H_ */
