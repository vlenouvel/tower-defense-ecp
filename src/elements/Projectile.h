/*
 * Projectile.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "ElementGraphique.h"
#include "ElementJeu.h"
#include "Coordonnees.h"
#include "Personnage.h"

class Projectile: public ElementGraphique, public ElementJeu {
public:
	Projectile(Coordonnees tCoord, Personnage* tCible, int tDommages);
	virtual ~Projectile();
	virtual void dessiner(sf::RenderWindow &pWindow) = 0;
	virtual void agir();
	Personnage* getCible();
	void setCible(Personnage* nouvelleCible);
	virtual void avancer() = 0;

protected:
	virtual void toucherEnnemi() = 0;
	int dommages;
	int vitesse;
	Coordonnees coordonnees;
	Personnage *cible;
};

#endif /* PROJECTILE_H_ */
