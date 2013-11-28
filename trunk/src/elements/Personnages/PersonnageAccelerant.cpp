/*
 * PersonnageAccelerant.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "PersonnageAccelerant.h"

PersonnageAccelerant::PersonnageAccelerant(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord) :
	Personnage(tVie,tVitesse,tArmure,tGain,tCoord){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spriteElement.setTexture(pResourcesLoader->texturePersonnageAccelerantDroite);
	spriteElement.setScale(0.23,0.23);
	vieDebut = vie;
	vitesseDebut = vitesse;
	barreDeVieVerte.setSize(sf::Vector2f(sf::Vector2f(spriteElement.getGlobalBounds().width, 5)));
}


PersonnageAccelerant::~PersonnageAccelerant(){
	// VIDE
}
void PersonnageAccelerant::avancer(){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	int abscisseAvant = coordonnees.getPosX();
	int ordonneeAvant = coordonnees.getPosY();
	vitesse = (int)vitesseDebut+10*(vieDebut - vie)/vieDebut;
	Personnage::avancer();
	int abscisseApres = coordonnees.getPosX();
	int ordonneeApres = coordonnees.getPosY();
	if (abscisseAvant - abscisseApres>0)
		spriteElement.setTexture(pResourcesLoader->texturePersonnageAccelerantGauche);
	else if (abscisseAvant - abscisseApres<0)
		spriteElement.setTexture(pResourcesLoader->texturePersonnageAccelerantDroite);
	else if (ordonneeAvant - ordonneeApres>0)
		spriteElement.setTexture(pResourcesLoader->texturePersonnageAccelerantHaut);
	else if (ordonneeAvant - ordonneeApres<0)
		spriteElement.setTexture(pResourcesLoader->texturePersonnageAccelerantBas);
}
