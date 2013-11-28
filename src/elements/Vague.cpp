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
	SOLIDE = 3,
	VOLANT = 4,
	GENERATEUR = 5,
	ACCELERANT = 6,
	DOUBLE = 7,
	BOSS = 8
};

Vague::Vague(int niveau) {
	ConfigManager *configManager = ConfigManager::getInstance();

	tempsEntrePop = sf::seconds((float)1);

	niveauType = (int)((niveau-1)/8) + 1;
	niveau = niveau  % 8;

	switch(niveau){
		case 1:
			nombrePersoRestant = configManager->mapVague1["nombre"];
			type = configManager->mapVague1["typePersos"];
			break;
		case 2:
			nombrePersoRestant = configManager->mapVague2["nombre"];
			type = configManager->mapVague2["typePersos"];
			break;
		case 3:
			nombrePersoRestant = configManager->mapVague3["nombre"];
			type = configManager->mapVague3["typePersos"];
			break;
		case 4:
			nombrePersoRestant = configManager->mapVague4["nombre"];
			type = configManager->mapVague4["typePersos"];
			break;
		case 5:
			nombrePersoRestant = configManager->mapVague5["nombre"];
			type = configManager->mapVague5["typePersos"];
			break;
		case 6:
			nombrePersoRestant = configManager->mapVague6["nombre"];
			type = configManager->mapVague6["typePersos"];
			break;
		case 7:
			nombrePersoRestant = configManager->mapVague7["nombre"];
			type = configManager->mapVague7["typePersos"];
			break;
		case 0:
			nombrePersoRestant = configManager->mapVague8["nombre"];
			type = configManager->mapVague8["typePersos"];
			break;
		default:
			break;
	}
}

void Vague::genererPersonnage()
{
	ResourceManager* ResourceManager = ResourceManager::getInstance();
	ConfigManager *configManager = ConfigManager::getInstance();

	int vie;
	int vitesse;
	int armure;
	int gain;
	Coordonnees coordonneesDepart(0,0);
	Personnage* pPersonnage = 0;
	switch (type) {
		case NORMAL:
			vie = configManager->mapPersonnageNormal["vie"]*pow(niveauType,3);
			vitesse = configManager->mapPersonnageNormal["vitesse"];
			armure = configManager->mapPersonnageNormal["armure"]*pow(niveauType,2);
			gain = configManager->mapPersonnageNormal["gain"]*niveauType;
			pPersonnage = new PersonnageBasique(vie, vitesse, armure, gain , coordonneesDepart);
			break;
		case RAPIDE:
			vie = configManager->mapPersonnageRapide["vie"]*pow(niveauType,3);
			vitesse = configManager->mapPersonnageRapide["vitesse"];
			armure = configManager->mapPersonnageRapide["armure"]*pow(niveauType,2);
			gain = configManager->mapPersonnageRapide["gain"]*niveauType;
			pPersonnage = new PersonnageBasique(vie, vitesse, armure, gain , coordonneesDepart);
			break;
		case SOLIDE:
			vie = configManager->mapPersonnageSolide["vie"]*pow(niveauType,3);
			vitesse = configManager->mapPersonnageSolide["vitesse"];
			armure = configManager->mapPersonnageSolide["armure"]*pow(niveauType,2);
			gain = configManager->mapPersonnageSolide["gain"]*niveauType;
			pPersonnage = new PersonnageBasique(vie, vitesse, armure, gain , coordonneesDepart);
			break;
		case VOLANT:
			vie = configManager->mapPersonnageVolant["vie"]*pow(niveauType,3);
			vitesse = configManager->mapPersonnageVolant["vitesse"];
			armure = configManager->mapPersonnageVolant["armure"]*pow(niveauType,2);
			gain = configManager->mapPersonnageVolant["gain"]*niveauType;
			pPersonnage = new PersonnageVolant(vie, vitesse, armure, gain , coordonneesDepart);
			break;
		case GENERATEUR:
			vie = configManager->mapPersonnageGenerateur["vie"]*pow(niveauType,3);
			vitesse = configManager->mapPersonnageGenerateur["vitesse"];
			armure = configManager->mapPersonnageGenerateur["armure"]*pow(niveauType,2);
			gain = configManager->mapPersonnageGenerateur["gain"]*niveauType;
			pPersonnage = new PersonnageGenerateur(vie, vitesse, armure, gain , coordonneesDepart);
			break;
		case ACCELERANT:
			vie = configManager->mapPersonnageAccelerant["vie"]*pow(niveauType,3);
			vitesse = configManager->mapPersonnageAccelerant["vitesse"];
			armure = configManager->mapPersonnageAccelerant["armure"]*pow(niveauType,2);
			gain = configManager->mapPersonnageAccelerant["gain"]*niveauType;
			pPersonnage = new PersonnageAccelerant(vie, vitesse, armure, gain , coordonneesDepart);
			break;
		case DOUBLE:
			vie = configManager->mapPersonnageDouble["vie"]*pow(niveauType,3);
			vitesse = configManager->mapPersonnageDouble["vitesse"];
			armure = configManager->mapPersonnageDouble["armure"]*pow(niveauType,2);
			gain = configManager->mapPersonnageDouble["gain"]*niveauType;
			pPersonnage = new PersonnageDouble(vie, vitesse, armure, gain , coordonneesDepart);
			break;
		case BOSS:
			vie = configManager->mapPersonnageBoss["vie"]*pow(niveauType,3);
			vitesse = configManager->mapPersonnageBoss["vitesse"];
			armure = configManager->mapPersonnageBoss["armure"]*pow(niveauType,2);
			gain = configManager->mapPersonnageBoss["gain"]*niveauType;
			pPersonnage = new SuperPersonnage(vie, vitesse, armure, gain , coordonneesDepart);
			break;
		default:
			break;
	}
	pPersonnage->trouverChemin(ResourceManager->getCarte());
	pPersonnage->ecrireChemin(ResourceManager->getCarte());
	ResourceManager->addPersonnage(pPersonnage);

	nombrePersoRestant--;
	if(nombrePersoRestant == 0)
	{
		tempsEntrePop = sf::seconds((float)15);
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
	// VIDE
}

