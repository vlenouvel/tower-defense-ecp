/*
 * Vague.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "Vague.h"

Vague::Vague(int niveau) {
	ConfigManager *configManager = ConfigManager::getInstance();

	tempsEntrePop = sf::seconds((float)1);

	niveauType = (int)((niveau-1)/8) + 1;
	niveau = (niveau-1) % 8;
	type = static_cast<TypePerso>(niveau);

	switch(type){
		case NORMAL:
			nombrePersoRestant = configManager->mapVagueNormal["nombre"];
			break;
		case RAPIDE:
			nombrePersoRestant = configManager->mapVagueRapide["nombre"];
			break;
		case SOLIDE:
			nombrePersoRestant = configManager->mapVagueSolide["nombre"];
			break;
		case VOLANT:
			nombrePersoRestant = configManager->mapVagueVolant["nombre"];
			break;
		case GENERATEUR:
			nombrePersoRestant = configManager->mapVagueGenerateur["nombre"];
			break;
		case ACCELERANT:
			nombrePersoRestant = configManager->mapVagueAccelerant["nombre"];
			break;
		case DOUBLE:
			nombrePersoRestant = configManager->mapVagueDouble["nombre"];
			break;
		case BOSS:
			nombrePersoRestant = configManager->mapVagueBoss["nombre"];
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
			vie = configManager->mapPersonnageNormal["vie"]*pow((float)niveauType,3);
			vitesse = configManager->mapPersonnageNormal["vitesse"];
			armure = configManager->mapPersonnageNormal["armure"]*pow((float)niveauType,2);
			gain = configManager->mapPersonnageNormal["gain"]*niveauType;
			pPersonnage = new PersonnageBasique(vie, vitesse, armure, gain , coordonneesDepart);
			break;
		case RAPIDE:
			vie = configManager->mapPersonnageRapide["vie"]*pow((float)niveauType,3);
			vitesse = configManager->mapPersonnageRapide["vitesse"];
			armure = configManager->mapPersonnageRapide["armure"]*pow((float)niveauType,2);
			gain = configManager->mapPersonnageRapide["gain"]*niveauType;
			pPersonnage = new PersonnageBasique(vie, vitesse, armure, gain , coordonneesDepart);
			break;
		case SOLIDE:
			vie = configManager->mapPersonnageSolide["vie"]*pow((float)niveauType,3);
			vitesse = configManager->mapPersonnageSolide["vitesse"];
			armure = configManager->mapPersonnageSolide["armure"]*pow((float)niveauType,2);
			gain = configManager->mapPersonnageSolide["gain"]*niveauType;
			pPersonnage = new PersonnageBasique(vie, vitesse, armure, gain , coordonneesDepart);
			break;
		case VOLANT:
			vie = configManager->mapPersonnageVolant["vie"]*pow((float)niveauType,3);
			vitesse = configManager->mapPersonnageVolant["vitesse"];
			armure = configManager->mapPersonnageVolant["armure"]*pow((float)niveauType,2);
			gain = configManager->mapPersonnageVolant["gain"]*niveauType;
			pPersonnage = new PersonnageVolant(vie, vitesse, armure, gain , coordonneesDepart);
			break;
		case GENERATEUR:
			vie = configManager->mapPersonnageGenerateur["vie"]*pow((float)niveauType,3);
			vitesse = configManager->mapPersonnageGenerateur["vitesse"];
			armure = configManager->mapPersonnageGenerateur["armure"]*pow((float)niveauType,2);
			gain = configManager->mapPersonnageGenerateur["gain"]*niveauType;
			pPersonnage = new PersonnageGenerateur(vie, vitesse, armure, gain , coordonneesDepart);
			break;
		case ACCELERANT:
			vie = configManager->mapPersonnageAccelerant["vie"]*pow((float)niveauType,3);
			vitesse = configManager->mapPersonnageAccelerant["vitesse"];
			armure = configManager->mapPersonnageAccelerant["armure"]*pow((float)niveauType,2);
			gain = configManager->mapPersonnageAccelerant["gain"]*niveauType;
			pPersonnage = new PersonnageAccelerant(vie, vitesse, armure, gain , coordonneesDepart);
			break;
		case DOUBLE:
			vie = configManager->mapPersonnageDouble["vie"]*pow((float)niveauType,3);
			vitesse = configManager->mapPersonnageDouble["vitesse"];
			armure = configManager->mapPersonnageDouble["armure"]*pow((float)niveauType,2);
			gain = configManager->mapPersonnageDouble["gain"]*niveauType;
			pPersonnage = new PersonnageDouble(vie, vitesse, armure, gain , coordonneesDepart);
			break;
		case BOSS:
			vie = configManager->mapPersonnageBoss["vie"]*pow((float)niveauType,3);
			vitesse = configManager->mapPersonnageBoss["vitesse"];
			armure = configManager->mapPersonnageBoss["armure"]*pow((float)niveauType,2);
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

