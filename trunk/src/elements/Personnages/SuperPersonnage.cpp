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
	barreDeVieVerte.setSize(sf::Vector2f(sf::Vector2f(spritePersonnage.getGlobalBounds().width, 5)));
	tailleSpriteInitial = spritePersonnage.getGlobalBounds().width;
}


SuperPersonnage::~SuperPersonnage(){
	// VIDE
}
void SuperPersonnage::avancer(){
	Personnage::avancer();
	double taille = (double)vie/(17*vieDebut);
	spritePersonnage.setScale(taille,taille);
	
}

void SuperPersonnage::dessiner(sf::RenderWindow &pWindow)
{
	barreDeVieRouge.setSize(sf::Vector2f(tailleSpriteInitial*(vieInitial - vie)/vieInitial,5));
	pWindow.draw(spritePersonnage);
	pWindow.draw(barreDeVieVerte);
	pWindow.draw(barreDeVieRouge);
}
