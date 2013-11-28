/*
 * TirDeGlace.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef TIRDEGLACE_H_
#define TIRDEGLACE_H_

#include "../Projectile.h"
#include "ExplosionMissile.h"
#include "../../ResourceManager.h"
#include "math.h"
#include "../../ResourcesLoader.h"
#include <SFML/Graphics.hpp>

class TirDeGlace: public Projectile {
public:
	TirDeGlace(Coordonnees tCoord, Personnage* tCible, int tDommages, int tRayonExplosion);
	void avancer();
	virtual ~TirDeGlace();
	void dessiner(sf::RenderWindow & rWindow);

private:
	void toucherEnnemi();
	int rayonExplosion;
	float rotation;
};

#endif /* TIRDEGLACE_H_ */
