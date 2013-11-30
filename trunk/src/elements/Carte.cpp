/*
 * Carte.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "Carte.h"

Carte::Carte() {

	pCaseSortie = new Case(680,560);
	for (int i=0; i<imageCarteX; i++){
		for (int j=0; j<imageCarteY; j++){
			Case* pCaseImageCarte = new Case(40*i,40*j);
			pCaseImageCarte->setHeuristique(pCaseSortie);
			imageCarte[i][j] = pCaseImageCarte;
		}
	}
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spriteElement.setTexture(pResourcesLoader->textureCarte);
	spriteElement.setScale(0.75,0.75);

}

Carte::~Carte() {
	// VIDE
}

void Carte::dessiner(sf::RenderWindow &pWindow){

	pWindow.draw(spriteElement);
}

void Carte::nettoyerCarte(){
	for (int i = 0; i<imageCarteX; i++){
		for (int j = 0; j<imageCarteY; j++){
			imageCarte[i][j]->setParcourue(false);
			imageCarte[i][j]->setDistanceEntree(0);
		}
	}
}
