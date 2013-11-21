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
	spritePersonnage.setTexture(pResourcesLoader->texturePersonnageBasiqueDroite);
	spritePersonnage.setScale(0.23,0.23);
}


PersonnageBasique::~PersonnageBasique(){
	// VIDE
}
void PersonnageBasique::agir(){Personnage::agirPersonnage();};
void PersonnageBasique::avancer(){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	int abscisseAvant = coordonnees.getPosX();
	int ordonneeAvant = coordonnees.getPosY();
	Personnage::avancerPersonnage();
	int abscisseApres = coordonnees.getPosX();
	int ordonneeApres = coordonnees.getPosY();
	if (abscisseAvant - abscisseApres>0)
		spritePersonnage.setTexture(pResourcesLoader->texturePersonnageBasiqueGauche);
	else if (abscisseAvant - abscisseApres<0)
		spritePersonnage.setTexture(pResourcesLoader->texturePersonnageBasiqueDroite);
	else if (ordonneeAvant - ordonneeApres>0)
		spritePersonnage.setTexture(pResourcesLoader->texturePersonnageBasiqueHaut);
	else if (ordonneeAvant - ordonneeApres<0)
		spritePersonnage.setTexture(pResourcesLoader->texturePersonnageBasiqueBas);
}
void PersonnageBasique::mourir(){Personnage::mourirPersonnage();};
void PersonnageBasique::perdrePV(int degat){
	if(degat > armure){
		vie -= (degat - armure);
		if(vie <= 0)
			this->mourir();
	}
};
void PersonnageBasique::dessiner(sf::RenderWindow &pWindow){Personnage::dessinerPersonnage(pWindow);};
int  PersonnageBasique::getVie(){return Personnage::getViePersonnage();};
void PersonnageBasique::arriver(){Personnage::arriverPersonnage();
delete this;};
Coordonnees PersonnageBasique::getCoordonnees(){return Personnage::getCoordonneesPersonnage();};
bool PersonnageBasique::trouverChemin(Carte * pCarte){return Personnage::trouverCheminPersonnage(pCarte);};
void PersonnageBasique::ecrireChemin(Carte * pCarte){Personnage::ecrireCheminPersonnage(pCarte);};