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
	spritePersonnage.setTexture(pResourcesLoader->texturePersonnageAccelerantDroite);
	spritePersonnage.setScale(0.23,0.23);
	vieDebut = vie;
	vitesseDebut = vitesse;
}


PersonnageAccelerant::~PersonnageAccelerant(){
	// VIDE
}
void PersonnageAccelerant::agir(){Personnage::agirPersonnage();};
void PersonnageAccelerant::avancer(){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	int abscisseAvant = coordonnees.getPosX();
	int ordonneeAvant = coordonnees.getPosY();
	vitesse = (int)vitesseDebut+10*(vieDebut - vie)/vieDebut;
	Personnage::avancerPersonnage();
	int abscisseApres = coordonnees.getPosX();
	int ordonneeApres = coordonnees.getPosY();
	if (abscisseAvant - abscisseApres>0)
		spritePersonnage.setTexture(pResourcesLoader->texturePersonnageAccelerantGauche);
	else if (abscisseAvant - abscisseApres<0)
		spritePersonnage.setTexture(pResourcesLoader->texturePersonnageAccelerantDroite);
	else if (ordonneeAvant - ordonneeApres>0)
		spritePersonnage.setTexture(pResourcesLoader->texturePersonnageAccelerantHaut);
	else if (ordonneeAvant - ordonneeApres<0)
		spritePersonnage.setTexture(pResourcesLoader->texturePersonnageAccelerantBas);
}
void PersonnageAccelerant::mourir(){Personnage::mourirPersonnage();};
void PersonnageAccelerant::perdrePV(int degat){
	if(degat > armure){
		vie -= (degat - armure);
		if(vie <= 0)
			this->mourir();
	}
};
void PersonnageAccelerant::dessiner(sf::RenderWindow &pWindow){Personnage::dessinerPersonnage(pWindow);};
int  PersonnageAccelerant::getVie(){return Personnage::getViePersonnage();};
void PersonnageAccelerant::arriver(){Personnage::arriverPersonnage();
delete this;};
Coordonnees PersonnageAccelerant::getCoordonnees(){return Personnage::getCoordonneesPersonnage();};
bool PersonnageAccelerant::trouverChemin(Carte * pCarte){return Personnage::trouverCheminPersonnage(pCarte);};
void PersonnageAccelerant::ecrireChemin(Carte * pCarte){Personnage::ecrireCheminPersonnage(pCarte);};