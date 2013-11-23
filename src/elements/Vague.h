/*
 * Vague.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef VAGUE_H_
#define VAGUE_H_

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include "../ResourceManager.h"
#include "GenerateurVague.h"
#include "ElementJeu.h"
#include "Personnage.h"
#include "Personnages/PersonnageBasique.h"
#include "Personnages/PersonnageDouble.h"
#include "Personnages/PersonnageGenerateur.h"
#include "Personnages/PersonnageVolant.h"
#include "Personnages/PersonnageAccelerant.h"
#include "Personnages/SuperPersonnage.h"
#include "Coordonnees.h"
#include <iostream>
#include "../ConfigManager.h"

class Vague: public ElementJeu {
public:
	Vague(int niveau);
	void agir();
	void genererPersonnage();
	virtual ~Vague();

private:
	int niveauType;
	int nombrePersoRestant;
	int type;
	sf::Clock horlogePop;
	sf::Time tempsEntrePop;
};

#endif /* VAGUE_H_ */
