/*
 * Carte.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "../ResourcesLoader.h"
#include "Carte.h"

Carte::Carte() {

	pCaseSortie = new Case(680,560);
	for (int i=0; i<18; i++){
		for (int j=0; j<15; j++){
			Case* pCaseImageCarte = new Case(40*i,40*j);
			pCaseImageCarte->setHeuristique(&(pCaseSortie->coordonneesCase));
			imageCarte[i][j] = pCaseImageCarte;
		}
	}
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	textureCarte = pResourcesLoader->textureCarte;
	spriteCarte.setTexture(textureCarte);
	spriteCarte.setScale(0.75,0.75);

}

Carte::~Carte() {
	// TODO Auto-generated destructor stub
}

void Carte::dessiner(sf::RenderWindow &pWindow){

	pWindow.draw(spriteCarte);
}

void Carte::nettoyerCarte(){
	for (int i = 0; i<18; i++){
		for (int j = 0; j<15; j++){
			imageCarte[i][j]->caseParcourue = false;
			imageCarte[i][j]->distanceEntree = 0;
		}
	}
}
