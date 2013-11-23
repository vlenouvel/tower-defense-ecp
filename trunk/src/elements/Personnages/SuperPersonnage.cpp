/*
 * SuperPersonnage.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "SuperPersonnage.h"

SuperPersonnage::SuperPersonnage(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord) : 
	Personnage(tVie,tVitesse,tArmure,tGain,tCoord){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spritePersonnage.setTexture(pResourcesLoader->textureSuperPersonnage);
	spritePersonnage.setScale(0.06,0.06);
	vieDebut = vie;
}


SuperPersonnage::~SuperPersonnage(){
	// VIDE
}
void SuperPersonnage::agir(){Personnage::agirPersonnage();}
void SuperPersonnage::avancer(){
	Personnage::avancerPersonnage();
	double taille = (double)vie/(17*vieDebut);
	spritePersonnage.setScale(taille,taille);
	
}
void SuperPersonnage::mourir(){
	Personnage::mourirPersonnage();
}
void SuperPersonnage::perdrePV(int degat){
	if(degat > armure){
		vie -= (degat - armure);
		if(vie <= 0)
			this->mourir();
	}
}
void SuperPersonnage::dessiner(sf::RenderWindow &pWindow){
	Personnage::dessinerPersonnage(pWindow);}
int  SuperPersonnage::getVie(){return Personnage::getViePersonnage();}
void SuperPersonnage::arriver(){Personnage::arriverPersonnage();
delete this;}
Coordonnees SuperPersonnage::getCoordonnees(){return Personnage::getCoordonneesPersonnage();}
bool SuperPersonnage::trouverChemin(Carte * pCarte){return Personnage::trouverCheminPersonnage(pCarte);}
void SuperPersonnage::ecrireChemin(Carte * pCarte){Personnage::ecrireCheminPersonnage(pCarte);}