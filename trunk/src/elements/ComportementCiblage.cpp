/*
 * ComportementCiblage.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "ComportementCiblage.h"

ComportementCiblage::ComportementCiblage() {

}

Personnage* ComportementCiblage::ciblerPlusFaible(std::vector<Personnage*> ciblesPossibles)
{
	/* Ici on va rechercher le personnage avec le moins de vie parmi les cibles possibles.
	 * Pour cela on utilisera la m�thode getVie des personnages, car l'attribut vie est prot�g�
	 * et donc innaccessible depuis les comportements.
	 */
	Personnage *cible(0);
	// Grande valeur initiale de vieMinimum (idealement infinie) pour trouver le min
	int vieMinimum(10000);
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
	ConfigManager *pConfigManager = ConfigManager::getInstance();
	int range = pConfigManager->mapTourCanon["rayonExplosion"];
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
			if ((pow((float)(xcible-xvoisin),2)+pow((float)(ycible-yvoisin),2))< pow((float)range,2))
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

	//apres test : la tour avec ce comportement attaquera le plus ancien ennemi � portee.
	//Dans beaucoup de cas, il s'agirat de l'ennemi le plus avance.
	//Est-ce suffisant ?

	return cible;
}

Personnage* ComportementCiblage::ciblerRandom(std::vector<Personnage*> ciblesPossibles)
{
	int indice = rand() % ciblesPossibles.size();
	return ciblesPossibles[indice];

}

ComportementCiblage::~ComportementCiblage() {
}

