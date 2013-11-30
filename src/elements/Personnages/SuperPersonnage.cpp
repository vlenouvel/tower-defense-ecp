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
	spriteElement.setTexture(pResourcesLoader->textureSuperPersonnage);
	spriteElement.setScale(0.06,0.06);
	vieDebut = vie;
	barreDeVieVerte.setSize(sf::Vector2f(sf::Vector2f(spriteElement.getGlobalBounds().width, 5)));
	tailleSpriteInitial = spriteElement.getGlobalBounds().width;
}


SuperPersonnage::~SuperPersonnage(){
	// VIDE
}
void SuperPersonnage::avancer(){
	Personnage::avancer();
	double taille = (double)vie/(17*vieDebut);
	spriteElement.setScale(taille,taille);
}

void SuperPersonnage::dessiner(sf::RenderWindow &pWindow)
{
	barreDeVieRouge.setSize(sf::Vector2f(tailleSpriteInitial*(vieInitial - vie)/vieInitial,5));
	pWindow.draw(spriteElement);
	pWindow.draw(barreDeVieVerte);
	pWindow.draw(barreDeVieRouge);
}
