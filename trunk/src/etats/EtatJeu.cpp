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

	Carte* pCarte = new Carte();

	manager->addCarte(pCarte);
}

void EtatJeu::dessiner(sf::RenderWindow &pWindow){
	ResourceManager* manager = ResourceManager::getInstance();

	carte = manager->getCarte();
	carte->dessiner(pWindow);

	Coordonnees coordonneesTest(10,10);
	TourAttaqueBasique* ptourTest = new TourAttaqueBasique(100,coordonneesTest,1);
	manager->addTour((Tour*) ptourTest);

	vector<Tour*> tourConteneur = manager->getTour();
	tourConteneur[0]->dessiner(pWindow);
}

void EtatJeu::handleEvent(sf::Event event)
{

}

EtatJeu::~EtatJeu() {
	// TODO Auto-generated destructor stub
}

