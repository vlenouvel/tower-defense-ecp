/*
 * CompCiblVieFaible.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "CompCiblVieFaible.h"

CompCiblVieFaible::CompCiblVieFaible() {
	// TODO Auto-generated constructor stub

}

CompCiblVieFaible::~CompCiblVieFaible() {
	// TODO Auto-generated destructor stub
}

Personnage* CompCiblVieFaible::cibler(std::vector<Personnage*> ciblesPossibles)
{
	/* Ici on va rechercher le personnage avec le moins de vie parmi les cibles possibles.
	 * Pour cela on utilisera la méthode getVie des personnages, car l'attribut vie est protégé
	 * et donc innaccessible depuis les comportements.
	 */
	Personnage *cible(0);
	int vieMinimum(0);
	for (int compteur(0); compteur< ciblesPossibles.size(); compteur++)
	{
		if (vieMinimum > ciblesPossibles[compteur]->getVie())
		{
			vieMinimum = ciblesPossibles[compteur]->getVie();
			cible = ciblesPossibles[compteur];
		}
	}
	return cible;
}
