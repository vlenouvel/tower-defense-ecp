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
	volant = true;
}


PersonnageVolant::~PersonnageVolant(){
	// VIDE
}
void PersonnageVolant::agir(){Personnage::agirPersonnage();};
void PersonnageVolant::avancer(){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	int abscisseAvant = coordonnees.getPosX();
	int ordonneeAvant = coordonnees.getPosY();
	Personnage::avancerPersonnage();
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
void PersonnageVolant::mourir(){Personnage::mourirPersonnage();};
void PersonnageVolant::perdrePV(int degat){
	if(degat > armure){
		vie -= (degat - armure);
		if(vie <= 0)
			this->mourir();
	}
};
void PersonnageVolant::dessiner(sf::RenderWindow &pWindow){Personnage::dessinerPersonnage(pWindow);};
int  PersonnageVolant::getVie(){return Personnage::getViePersonnage();};
void PersonnageVolant::arriver(){Personnage::arriverPersonnage();
delete this;};
Coordonnees PersonnageVolant::getCoordonnees(){return Personnage::getCoordonneesPersonnage();};
bool PersonnageVolant::trouverChemin(Carte * pCarte){return Personnage::trouverCheminPersonnage(pCarte);};
void PersonnageVolant::ecrireChemin(Carte * pCarte){Personnage::ecrireCheminPersonnage(pCarte);};