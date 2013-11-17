/*
 * CanonLourd.h
 *
 *  TowerDefense ECP
 *      
 */

#ifndef CANONLOURD_H_
#define CANONLOURD_H_

#include "TourAttaque.h"
#include "ProjectileExplosif.h"

class CanonLourd: public TourAttaque {
public:
	CanonLourd(int tPrix, Coordonnees tCoord);
	virtual ~CanonLourd();
	void dessiner(sf::RenderWindow & rWindow);

private:
	sf::Sound sonTirCanonLourd;
	void attaque(Personnage* (*fonctionCiblage)(std::vector<Personnage*> ciblesPossibles));
	int rayonExplosion;
	sf::Texture textureCanonLourd;
	sf::Sprite spriteCanonLourd;
};

#endif /* CANONLOURD_H_ */
