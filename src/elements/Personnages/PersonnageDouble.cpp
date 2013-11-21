/*
 * PersonnageDouble.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "PersonnageDouble.h"

PersonnageDouble::PersonnageDouble(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord) : 
	Personnage(tVie,tVitesse,tArmure,tGain,tCoord){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spritePersonnage.setTexture(pResourcesLoader->texturePersonnageDouble);
	spritePersonnage.setScale(0.09,0.13);
}


PersonnageDouble::~PersonnageDouble(){
	// VIDE
}

void PersonnageDouble::mourir(){
	ResourceManager* ResourceManager = ResourceManager::getInstance();
	Coordonnees coordonneesDepart(this->coordonnees.getPosX(),this->coordonnees.getPosY());
	Personnage* pPersonnage1 = new Personnage((int)this->vie/2, vitesse, this->armure, (int)this->gain/2 , coordonneesDepart);
	ResourceManager->addPersonnage(pPersonnage1);
	Personnage* pPersonnage2 = new Personnage((int)this->vie/2, vitesse, this->armure, (int)this->gain/2 , coordonneesDepart);
	ResourceManager->addPersonnage(pPersonnage2);
	Personnage::mourir();
}