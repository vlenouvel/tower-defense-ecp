/*
 * ExplosionMissile.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef EXPLOSIONMISSILE_H_
#define EXPLOSIONMISSILE_H_

#include "../../ResourceManager.h"
#include "../../ResourcesLoader.h"
#include "../ElementGraphique.h"
#include <SFML/Graphics.hpp>

class ExplosionMissile: public ElementGraphique{
public:
	ExplosionMissile(Coordonnees tCoord);
	virtual ~ExplosionMissile();
	void dessiner(sf::RenderWindow & rWindow);

private:
	int momentDuCycle;
};

#endif /* EXPLOSIONMISSILE_H_ */
