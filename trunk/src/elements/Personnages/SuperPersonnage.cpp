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
void SuperPersonnage::avancer(){
	Personnage::avancer();
	double taille = (double)vie/(17*vieDebut);
	spritePersonnage.setScale(taille,taille);
	
}
