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
#include "math.h"
#include <SFML/Graphics.hpp>

class Missile: public Projectile {
public:
	Missile(Coordonnees tCoord, Personnage* tCible, int tDommages, int tRayonExplosion);
	void avancer();
	virtual ~Missile();
	void dessiner(sf::RenderWindow & rWindow);

private:
	int rayonExplosion;
	int momentDuCycle;
	float rotation;
	sf::Sprite spriteTrainee;
	void toucherEnnemi();
};

#endif /* MISSILE_H_ */
