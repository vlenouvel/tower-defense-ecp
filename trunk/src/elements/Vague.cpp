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
	ResourceManager* ResourceManager = ResourceManager::getInstance();
	ConfigManager *configManager = ConfigManager::getInstance();

	int vie;
	int vitesse;
	int armure;
	switch (type) {
		case NORMAL:
			vie = configManager->mapPersonnageNormal["vie"];
			vitesse = configManager->mapPersonnageNormal["vitesse"];
			armure = configManager->mapPersonnageNormal["armure"];
			break;
		case RAPIDE:
			vie = configManager->mapPersonnageRapide["vie"];
			vitesse = configManager->mapPersonnageRapide["vitesse"];
			armure = configManager->mapPersonnageRapide["armure"];
			break;
		case SOLIDE:
			vie = configManager->mapPersonnageSolide["vie"];
			vitesse = configManager->mapPersonnageSolide["vitesse"];
			armure = configManager->mapPersonnageSolide["armure"];
			break;
		default:
			break;
	}

	int gain = 0;
	Coordonnees coordonneesDepart(0,0);
	Personnage* pPersonnage = new PersonnageVolant(1000, 5, 10, gain , coordonneesDepart);
	pPersonnage->trouverChemin(ResourceManager->getCarte());
	pPersonnage->ecrireChemin(ResourceManager->getCarte());
	ResourceManager->addPersonnage(pPersonnage);

	nombrePersoRestant--;
	if(nombrePersoRestant == 0)
	{
		ResourceManager->addVague(0);
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

