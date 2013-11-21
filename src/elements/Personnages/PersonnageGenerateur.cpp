/*
 * PersonnageGenerateur.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "PersonnageGenerateur.h"
#include "PersonnageBasique.h"
PersonnageGenerateur::PersonnageGenerateur(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord) : 
	Personnage(tVie,tVitesse,tArmure,tGain,tCoord){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spritePersonnage.setTexture(pResourcesLoader->texturePersonnageGenerateurDroite);
	spritePersonnage.setScale(0.4,0.4);
	compteurCreation = 0;
}


PersonnageGenerateur::~PersonnageGenerateur(){
	// VIDE
}
void PersonnageGenerateur::agir(){
	ResourceManager* ResourceManager = ResourceManager::getInstance();
	compteurCreation++;
	Personnage::agirPersonnage();
	if (compteurCreation%40 == 0){
		Coordonnees coordonneesDepart(this->coordonnees.getPosX(),this->coordonnees.getPosY());
		Personnage* pPersonnage = new PersonnageBasique((int)this->vie/5, 3*vitesse, (int)this->armure/5, (int)this->gain/5 , coordonneesDepart);
		pPersonnage->trouverChemin(ResourceManager->getCarte());
		pPersonnage->ecrireChemin(ResourceManager->getCarte());
		ResourceManager->addPersonnage(pPersonnage);
	}
}
void PersonnageGenerateur::avancer(){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	int abscisseAvant = coordonnees.getPosX();
	int ordonneeAvant = coordonnees.getPosY();
	Personnage::avancerPersonnage();
	int abscisseApres = coordonnees.getPosX();
	int ordonneeApres = coordonnees.getPosY();
	if (abscisseAvant - abscisseApres>0)
		spritePersonnage.setTexture(pResourcesLoader->texturePersonnageGenerateurGauche);
	else if (abscisseAvant - abscisseApres<0)
		spritePersonnage.setTexture(pResourcesLoader->texturePersonnageGenerateurDroite);
	else if (ordonneeAvant - ordonneeApres>0)
		spritePersonnage.setTexture(pResourcesLoader->texturePersonnageGenerateurHaut);
	else if (ordonneeAvant - ordonneeApres<0)
		spritePersonnage.setTexture(pResourcesLoader->texturePersonnageGenerateurBas);
}
void PersonnageGenerateur::mourir(){Personnage::mourirPersonnage();};
void PersonnageGenerateur::perdrePV(int degat){
	if(degat > armure){
		vie -= (degat - armure);
		if(vie <= 0)
			this->mourir();
	}
};
void PersonnageGenerateur::dessiner(sf::RenderWindow &pWindow){Personnage::dessinerPersonnage(pWindow);};
int  PersonnageGenerateur::getVie(){return Personnage::getViePersonnage();};
void PersonnageGenerateur::arriver(){Personnage::arriverPersonnage();
delete this;};
Coordonnees PersonnageGenerateur::getCoordonnees(){return Personnage::getCoordonneesPersonnage();};
bool PersonnageGenerateur::trouverChemin(Carte * pCarte){return Personnage::trouverCheminPersonnage(pCarte);};
void PersonnageGenerateur::ecrireChemin(Carte * pCarte){Personnage::ecrireCheminPersonnage(pCarte);};