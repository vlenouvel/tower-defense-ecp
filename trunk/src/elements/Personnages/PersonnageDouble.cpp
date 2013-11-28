/*
 * PersonnageDouble.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "PersonnageDouble.h"
#include "PersonnageBasique.h"
PersonnageDouble::PersonnageDouble(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord) :
	Personnage(tVie,tVitesse,tArmure,tGain,tCoord){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spriteElement.setTexture(pResourcesLoader->texturePersonnageDoubleDroite);
	spriteElement.setScale(0.25,0.25);
	barreDeVieVerte.setSize(sf::Vector2f(sf::Vector2f(spriteElement.getGlobalBounds().width, 5)));
}


PersonnageDouble::~PersonnageDouble(){
	// VIDE
}

void PersonnageDouble::mourir(){
	ResourceManager* ResourceManager = ResourceManager::getInstance();
	Coordonnees coordonneesDepart1(this->coordonnees.getPosX(),this->coordonnees.getPosY());
	Personnage* pPersonnage1 = new PersonnageBasique((int)this->vie/2, vitesse, this->armure, (int)this->gain/2 , coordonneesDepart1);
	pPersonnage1->trouverChemin(ResourceManager->getCarte());
	pPersonnage1->ecrireChemin(ResourceManager->getCarte());
	ResourceManager->addPersonnage(pPersonnage1);
	Coordonnees coordonneesDepart2(this->coordonnees.getPosX(),this->coordonnees.getPosY());
	Personnage* pPersonnage2 = new PersonnageBasique((int)this->vie/2, vitesse, this->armure, (int)this->gain/2 , coordonneesDepart2);
	pPersonnage2->trouverChemin(ResourceManager->getCarte());
	pPersonnage2->ecrireChemin(ResourceManager->getCarte());
	ResourceManager->addPersonnage(pPersonnage2);
	Personnage::mourir();
}

void PersonnageDouble::avancer(){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	int abscisseAvant = coordonnees.getPosX();
	int ordonneeAvant = coordonnees.getPosY();
	Personnage::avancer();
	int abscisseApres = coordonnees.getPosX();
	int ordonneeApres = coordonnees.getPosY();
	if (abscisseAvant - abscisseApres>0)
		spriteElement.setTexture(pResourcesLoader->texturePersonnageDoubleGauche);
	else if (abscisseAvant - abscisseApres<0)
		spriteElement.setTexture(pResourcesLoader->texturePersonnageDoubleDroite);
	else if (ordonneeAvant - ordonneeApres>0)
		spriteElement.setTexture(pResourcesLoader->texturePersonnageDoubleHaut);
	else if (ordonneeAvant - ordonneeApres<0)
		spriteElement.setTexture(pResourcesLoader->texturePersonnageDoubleBas);
}
