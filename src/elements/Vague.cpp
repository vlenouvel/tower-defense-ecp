/*
 * Vague.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "Vague.h"

enum TypePerso {
	NORMAL = 1,
	RAPIDE = 2,
	SOLIDE = 3
};

Vague::Vague(int niveau) {
	// TODO Fixer le bon nombre de type d'unites
	nombreType = 3;

	tempsEntrePop = sf::seconds((float)1);

	// Le niveau du type du personnage cree
	niveauType = (niveau / nombreType) + 1;

	nombrePersoRestant = 5;

	// Le type de l'unite
	type = niveau % nombreType;
	if (type == 0) {
		type = nombreType;
		niveauType = niveauType - 1;
	}

	// TODO A supprimer
	std::cout << "Vague creee avec des personnages de Type : " << type << " et de niveau " << niveauType << std::endl;

}

void Vague::genererPersonnage()
{
	ResourceManager* manager = ResourceManager::getInstance();


	// TODO Parametre des unites totalement arbitraire
	int vie;
	int vitesse;
	int armure;
	switch (type) {
		case NORMAL:
			vie = 10;
			vitesse = 5;
			armure = 2;
			break;
		case RAPIDE:
			vie = 5;
			vitesse = 10;
			armure = 1;
			break;
		case SOLIDE:
			vie = 30;
			vitesse = 2;
			armure = 5;
			break;
		default:
			break;
	}

	// TODO Changer l'aspect random du positionnement
	Coordonnees coordonneesDepart(rand()%800,rand()%600);
	Personnage* pPersonnage = new Personnage(vie, vitesse, armure, coordonneesDepart);
	manager->addPersonnage(pPersonnage);

	// TODO A supprimer
	vector<Personnage*> pPerso = manager->getPersonnage();
	int testVie = pPerso.back()->getVie();
	int s = pPerso.size();
	std::cout << "Taille du vecteur Personnage " << s << " personnages et vie du dernier perso =" << testVie <<std::endl;

	nombrePersoRestant--;
	if(nombrePersoRestant == 0)
	{
		manager->addVague(0);
		delete this;
	}

}

void Vague::agir()
{
	if(horlogePop.getElapsedTime() >= tempsEntrePop)
	{
		genererPersonnage();
		horlogePop.restart();
	}

}

Vague::~Vague() {
	// TODO Auto-generated destructor stub
}

