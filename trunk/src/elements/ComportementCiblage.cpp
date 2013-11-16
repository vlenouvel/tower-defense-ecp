/*
 * ComportementCiblage.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "ComportementCiblage.h"

ComportementCiblage::ComportementCiblage() {

}

Personnage* ComportementCiblage::ciblerPlusFaible(std::vector<Personnage*> ciblesPossibles)
{
	/* Ici on va rechercher le personnage avec le moins de vie parmi les cibles possibles.
	 * Pour cela on utilisera la méthode getVie des personnages, car l'attribut vie est protégé
	 * et donc innaccessible depuis les comportements.
	 */
	Personnage *cible(0);
	// Grande valeur initiale de vieMinimum (idealement infinie) pour trouver le min
	int vieMinimum(1000);
	for (unsigned int compteur(0); compteur < ciblesPossibles.size(); compteur++)
	{
		if (vieMinimum > ciblesPossibles[compteur]->getVie())
		{
			vieMinimum = ciblesPossibles[compteur]->getVie();
			cible = ciblesPossibles[compteur];
		}
	}
	return cible;
}

Personnage* ComportementCiblage::ciblerZone(std::vector<Personnage*> ciblesPossibles)
	{
	/* Ici on va rechercher, parmi les cibles possibles, le personnage qui a le plus de personnages voisins dans un rayon de valeur"range".
	 */
	//TODO : On ne peut pas envoyer la range en paramètre car on ne peut pas changer le prototype de la fonction
	// Il faut donc trouver un moyen de l'obtenir autrement
	int range = 10;
	ResourceManager *manager = ResourceManager::getInstance();
	std::vector<Personnage*> tousLesPersonnages = manager->getPersonnage();
	Personnage *cible(0);
	int nombredevoisinsmax(0);
	std::vector <int> nombredevoisins (ciblesPossibles.size(), 0);
	for (unsigned int compteur(0); compteur < ciblesPossibles.size(); compteur++)
	{
		for (unsigned int i(0); i< tousLesPersonnages.size(); i++)
		{
			double xcible= ciblesPossibles[compteur]->getCoordonnees().getPosX();
			double ycible= ciblesPossibles[compteur]->getCoordonnees().getPosY();
			double xvoisin= tousLesPersonnages[i]->getCoordonnees().getPosX();
			double yvoisin= tousLesPersonnages[i]->getCoordonnees().getPosY();
			if ((pow((xcible-xvoisin),2)+pow((ycible-yvoisin),2))< pow(range,2))
			{
					nombredevoisins[compteur]++;
			}
		}
		if (nombredevoisinsmax < nombredevoisins[compteur])
		{
			nombredevoisinsmax = nombredevoisins[compteur];
			cible = ciblesPossibles[compteur];
		}
	}
	return cible;
}

Personnage* ComportementCiblage::ciblerPremier(std::vector<Personnage*> ciblesPossibles)
{
	Personnage *cible(0);
	//on va tenter de voir si une idee simple donne le bon resultat

	cible=ciblesPossibles[0];

	//apres test : la tour avec ce comportement attaquera le plus ancien ennemi à portee.
	//Dans beaucoup de cas, il s'agirat de l'ennemi le plus avance.
	//Est-ce suffisant ?

	return cible;
}

ComportementCiblage::~ComportementCiblage() {
}

