/*
 * TourAttaque.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef TOURATTAQUE_H_
#define TOURATTAQUE_H_

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include "../ComportementCiblage.h"
#include "Tour.h"
#include "../../ResourceManager.h"
#include "../Projectile.h"
#include "math.h"
#include "../../ConfigManager.h"
#include "TourSupport.h"

class TourAttaque: public Tour {
public:
	TourAttaque(Coordonnees tCoord);
	void virtual changerComportementCiblage(ComportementCiblage::Comportement nouveauComportement);
	void agir();
	virtual ~TourAttaque();
	virtual void actionSpeciale()=0;
	virtual void dessiner(sf::RenderWindow &pWindow);
	virtual void monterNiveau();
	virtual bool isTourAttaque();
	virtual int getDommages();
	ComportementCiblage::Comportement getComportement();
	virtual void addAmelioration(int amelio);
	virtual	void removeAmelioration(int amelio);

protected:
	// On utilise un pointeur vers une fonction statique pour le ciblage
	// On peut ainsi changer a la volee le ciblage de la tour
	// en changeant la fonction sur laquelle est le pointeur.
	void virtual attaque(Personnage* (*fonctionCiblage)(std::vector<Personnage*> ciblesPossibles)) = 0;
	void trouverCibles();
	void virtual calculerValeursAmeliorees();
	Personnage* (*pCibler)(std::vector<Personnage*> ciblesPossibles);
	int attackDamage;
	int attackRange;
	ComportementCiblage::Comportement comportementChoisi;
	std::vector<Personnage*> ciblesPossibles;
	sf::Time timeBetweenAttacks;
	sf::Clock clockFromLastAttack;
	int amelioration;

	int attackDamageBuffed;
	int attackRangeBuffed;
	sf::Time timeBetweenAttacksBuffed;
};

#endif /* TOURATTAQUE_H_ */
