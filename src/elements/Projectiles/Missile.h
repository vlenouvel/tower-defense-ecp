/*
 * Missile.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef MISSILE_H_
#define MISSILE_H_

#include "../Projectile.h"
#include "ExplosionMissile.h"
#include "../../ResourceManager.h"
#include "math.h"
#include "../../ResourcesLoader.h"
#include <SFML/Graphics.hpp>

class Missile: public Projectile {
public:
	Missile(Coordonnees tCoord, Personnage* tCible, int tDommages, int tRayonExplosion);
	void avancer();
	void toucherEnnemi();
	virtual ~Missile();
	void dessiner(sf::RenderWindow & rWindow);

private:
	int rayonExplosion;
	int momentDuCycle;
	float rotation;
	sf::Sprite spriteTrainee;
};

#endif /* MISSILE_H_ */
