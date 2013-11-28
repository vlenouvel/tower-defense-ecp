/*
 * PersonnageBasique.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "PersonnageBasique.h"

PersonnageBasique::PersonnageBasique(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord) :
	Personnage(tVie,tVitesse,tArmure,tGain,tCoord){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spriteElement.setTexture(pResourcesLoader->texturePersonnageBasiqueDroite);
	spriteElement.setScale(0.23,0.23);
	barreDeVieVerte.setSize(sf::Vector2f(sf::Vector2f(spriteElement.getGlobalBounds().width, 5)));
}


PersonnageBasique::~PersonnageBasique(){
	// VIDE
}
void PersonnageBasique::avancer(){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	int abscisseAvant = coordonnees.getPosX();
	int ordonneeAvant = coordonnees.getPosY();
	Personnage::avancer();
	int abscisseApres = coordonnees.getPosX();
	int ordonneeApres = coordonnees.getPosY();
	if (abscisseAvant - abscisseApres>0)
		spriteElement.setTexture(pResourcesLoader->texturePersonnageBasiqueGauche);
	else if (abscisseAvant - abscisseApres<0)
		spriteElement.setTexture(pResourcesLoader->texturePersonnageBasiqueDroite);
	else if (ordonneeAvant - ordonneeApres>0)
		spriteElement.setTexture(pResourcesLoader->texturePersonnageBasiqueHaut);
	else if (ordonneeAvant - ordonneeApres<0)
		spriteElement.setTexture(pResourcesLoader->texturePersonnageBasiqueBas);
}
