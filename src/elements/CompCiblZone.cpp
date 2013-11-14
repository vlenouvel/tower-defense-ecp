/*
 * CompCiblZone.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "CompCiblZone.h"

CompCiblZone::CompCiblZone() {
	// TODO Auto-generated constructor stub

}

CompCiblZone::~CompCiblZone() {
	// TODO Auto-generated destructor stub
}

Personnage* CompCiblZone::cibler(std::vector<Personnage*>* ciblesPossibles, std::vector<Personnage*>*touslespersonnages, float range)
	{
	/* Ici on va rechercher, parmi les cibles possibles, le personnage qui a le plus de personnages voisins dans un rayon de valeur"range".
	 */
	Personnage *cible(0);
	int nombredevoisinsmax(0);
	std::vector <int> nombredevoisins (ciblesPossibles->size(), 0);
	for (int compteur(0); compteur< ciblesPossibles->size(); compteur++)
	{
		for (int i(0); i< touslespersonnages->size(); i++)
		{
			int xcible= (*ciblesPossibles)[compteur]-> getCoordonnees().getPosX();
			int ycible= (*ciblesPossibles)[compteur]-> getCoordonnees().getPosY();
			int xvoisin= (*touslespersonnages)[i]-> getCoordonnees().getPosX();
			int yvoisin= (*touslespersonnages)[i]-> getCoordonnees().getPosY();
			if (sqrt((xcible-xvoisin)^(2)+(ycible-yvoisin)^(2))<range)
			{
					nombredevoisins[compteur]++;
			}
		}
		if (nombredevoisinsmax < nombredevoisins[compteur])
		{
			nombredevoisinsmax = nombredevoisins[compteur];
			cible = (*ciblesPossibles)[compteur];
		}
	}
	return cible;
}

