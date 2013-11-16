/*
 * CompCiblZone.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "CompCiblZone.h"
#include "math.h"
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
			double xcible= (*ciblesPossibles)[compteur]-> getCoordonnees().getPosX();
			double ycible= (*ciblesPossibles)[compteur]-> getCoordonnees().getPosY();
			double xvoisin= (*touslespersonnages)[i]-> getCoordonnees().getPosX();
			double yvoisin= (*touslespersonnages)[i]-> getCoordonnees().getPosY();
			if ((pow((float)(xcible-xvoisin),2)+pow((float)(ycible-yvoisin),2))< pow((float)range,2))
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

