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
	textureMur = pResourcesLoader->textureMur;
	spriteMur.setTexture(textureMur);
	spriteMur.setPosition((float)(tCoord.posX/40)*40,floor((float)(tCoord.posY/40))*40);
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
	pWindow.draw(spriteMur);
}
