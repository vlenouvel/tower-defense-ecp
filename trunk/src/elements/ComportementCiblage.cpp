/*
 * ComportementCiblage.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "ComportementCiblage.h"

ComportementCiblage::ComportementCiblage() {

}

Personnage* ComportementCiblage::ciblerPlusProche(std::vector<Personnage*> ciblesPossibles)
{
	/* Ici, on va rechercher le personnage qui est le plus proche de l'object
	 * Pour cela on va lire la taille du chemin restant a parcourir pour chaque perso,
	 * et prendre celui qui a la valeur la plus faible
	 */
	assert(ciblesPossibles.size() > 0);
	Personnage *cible(0);
	int tailleMinimum(1000);
	for (unsigned int compteur(0); compteur < ciblesPossibles.size(); compteur++)
		{
			if (tailleMinimum > ciblesPossibles[compteur]->getTailleChemin())
			{
				tailleMinimum = ciblesPossibles[compteur]->getTailleChemin();
				cible = ciblesPossibles[compteur];
			}
		}
		assert(cible != 0);
		return cible;
}


Personnage* ComportementCiblage::ciblerPlusFaible(std::vector<Personnage*> ciblesPossibles)
{
	/* Ici on va rechercher le personnage avec le moins de vie parmi les cibles possibles.
	 * Pour cela on utilisera la m�thode getVie des personnages, car l'attribut vie est prot�g�
	 * et donc innaccessible depuis les comportements.
	 */
	Personnage *cible(0);
	assert(ciblesPossibles.size() > 0);
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
	assert(cible != 0);
	return cible;
}

Personnage* ComportementCiblage::ciblerZone(std::vector<Personnage*> ciblesPossibles)
	{
	/* Ici on va rechercher, parmi les cibles possibles, le personnage qui a le plus de personnages voisins dans un rayon de valeur"range".
	 */
	assert(ciblesPossibles.size() > 0);
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
	assert(cible != 0);
	return cible;
}

Personnage* ComportementCiblage::ciblerRandom(std::vector<Personnage*> ciblesPossibles)
{
	/*
	 * On choisi une des cibles au hasard dans ceux disponibles
	 */
	assert(ciblesPossibles.size() > 0);
	int indice = rand() % ciblesPossibles.size();
	Personnage* cible = ciblesPossibles[indice];
	assert(cible != 0);
	return cible;

}

ComportementCiblage::~ComportementCiblage() {
}

