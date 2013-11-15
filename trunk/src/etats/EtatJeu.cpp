/*
 * EtatJeu.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "EtatJeu.h"
#include <iostream>

using namespace std;

EtatJeu::EtatJeu(App *tApp) : Etat(tApp) {
	ResourceManager* manager = ResourceManager::getInstance();

	// Creation de la carte
	carte = new Carte();
	pRessources = new Ressources();
	manager->addCarte(carte);

}

void EtatJeu::dessiner(sf::RenderWindow &pWindow){
	ResourceManager* manager = ResourceManager::getInstance();
	carte->dessiner(pWindow);
	pRessources->dessiner(pWindow);

	/*Coordonnees coordonneesTest(20,20);
	TourAttaqueBasique* ptourTest = new TourAttaqueBasique(100,coordonneesTest,1);
	manager->addTour((Tour*) ptourTest);*/

	vector<Tour*> tourConteneur = manager->getTour();
	if (!tourConteneur.empty()){
		for(int i=0;i<tourConteneur.size();i++){
			tourConteneur[i]->dessiner(pWindow);
		}
	}
}

void EtatJeu::handleEvent(sf::Event event)
{
	ResourceManager* manager = ResourceManager::getInstance();
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			Coordonnees coordonneesTour((int)event.mouseButton.x,(int)event.mouseButton.y);
			TourAttaqueBasique* ptourTest = new TourAttaqueBasique(100,coordonneesTour,1);
			manager->addTour((Tour*) ptourTest);
			cout << ptourTest->coordonnees.posX << endl;
			cout << manager->getTour()[0]->coordonnees.posX << endl;
		}
	}
}

EtatJeu::~EtatJeu() {
	// TODO Auto-generated destructor stub
}

