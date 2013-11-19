/*
 * Vague.cpp
 *
 *  TowerDefense ECP
 *       
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
			vitesse = 3;
			armure = 5;
			break;
		default:
			break;
	}

	Coordonnees coordonneesDepart(0,0);
	Personnage* pPersonnage = new Personnage(niveauType*vie, vitesse, armure, coordonneesDepart);
	pPersonnage->trouverChemin(manager->getCarte());
	pPersonnage->ecrireChemin(manager->getCarte());
	manager->addPersonnage(pPersonnage);

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

