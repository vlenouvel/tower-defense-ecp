/*
 * CompCiblVieFaible.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "CompCiblVieFaible.h"

CompCiblVieFaible::CompCiblVieFaible() {
	// TODO Auto-generated constructor stub

}

CompCiblVieFaible::~CompCiblVieFaible() {
	// TODO Auto-generated destructor stub
}

Personnage* CompCiblVieFaible::cibler(std::vector<Personnage*>* ciblesPossibles)
{
	/* Ici on va rechercher le personnage avec le moins de vie parmi les cibles possibles.
	 * Pour cela on utilisera la m�thode getVie des personnages, car l'attribut vie est prot�g�
	 * et donc innaccessible depuis les comportements.
	 */
	Personnage *cible(0);
	int vieMinimum(0);
	for (unsigned int compteur(0); compteur< ciblesPossibles->size(); compteur++)
	{
		if (vieMinimum > (*ciblesPossibles)[compteur]->getVie())
		{
			vieMinimum = (*ciblesPossibles)[compteur]->getVie();
			cible = (*ciblesPossibles)[compteur];
		}
	}
	return cible;
}
