/*
 * Carte.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "../ResourcesLoader.h"
#include "Carte.h"

Carte::Carte() {
	pCaseSortie = new Case(20,1);
	for (int i=0; i<20; i++){
		for (int j=0; j<15; j++){
			Case* pCaseImageCarte = new Case(40*i,40*j);
			pCaseImageCarte->setHeuristique(&(pCaseSortie->coordonneesCase));
			imageCarte[i][j] = pCaseImageCarte;
		}
	}
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	textureCarte = pResourcesLoader->textureCarte;
	spriteCarte.setTexture(textureCarte);
	spriteCarte.setScale(0.88,0.88);

}

Carte::~Carte() {
	// TODO Auto-generated destructor stub
}

void Carte::dessiner(sf::RenderWindow &pWindow){

	pWindow.draw(spriteCarte);
}
