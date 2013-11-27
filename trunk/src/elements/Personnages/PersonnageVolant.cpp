/*
 * PersonnageBasique.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "PersonnageVolant.h"

PersonnageVolant::PersonnageVolant(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord) :
	Personnage(tVie,tVitesse,tArmure,tGain,tCoord){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spritePersonnage.setTexture(pResourcesLoader->texturePersonnageVolantDroite);
	spritePersonnage.setScale(0.4,0.4);
	barreDeVieVerte.setSize(sf::Vector2f(sf::Vector2f(spritePersonnage.getGlobalBounds().width, 5)));
}


PersonnageVolant::~PersonnageVolant(){
	// VIDE
}
void PersonnageVolant::avancer(){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	int abscisseAvant = coordonnees.getPosX();
	int ordonneeAvant = coordonnees.getPosY();
	Personnage::avancer();
	int abscisseApres = coordonnees.getPosX();
	int ordonneeApres = coordonnees.getPosY();
	if (abscisseAvant - abscisseApres>0)
		spritePersonnage.setTexture(pResourcesLoader->texturePersonnageVolantGauche);
	else if (abscisseAvant - abscisseApres<0)
		spritePersonnage.setTexture(pResourcesLoader->texturePersonnageVolantDroite);
	else if (ordonneeAvant - ordonneeApres>0)
		spritePersonnage.setTexture(pResourcesLoader->texturePersonnageVolantHaut);
	else if (ordonneeAvant - ordonneeApres<0)
		spritePersonnage.setTexture(pResourcesLoader->texturePersonnageVolantBas);
}

bool PersonnageVolant::isVolant()
{
	return true;
}
