/*
 * Mur.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "Mur.h"

Mur::Mur(Coordonnees tCoord) : Batiment(tCoord) {
	prix = 1;
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spriteElement.setTexture(pResourcesLoader->textureMur);
	spriteElement.setPosition((float)(tCoord.getPosX()/40)*40,floor((float)(tCoord.getPosY()/40))*40);
}

bool Mur::isTour()
{
	return false;
}

void Mur::agir()
{

}

Mur::~Mur() {
	// VIDE
}


void Mur::dessiner(sf::RenderWindow &pWindow){
	pWindow.draw(spriteElement);
}
