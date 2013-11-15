/*
 * EtatJeu.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "EtatJeu.h"

using namespace std;

EtatJeu::EtatJeu(App *tApp) : Etat(tApp) {
	ResourceManager* manager = ResourceManager::getInstance();

	// Creation de la carte
	carte = new Carte();
	pRessources = new Ressources();
	pTableauDeBord = new TableauDeBord();
	manager->addCarte(carte);
	typeTourChoisi = 1;

}

void EtatJeu::dessiner(sf::RenderWindow &pWindow){
	ResourceManager* manager = ResourceManager::getInstance();
	carte->dessiner(pWindow);
	pRessources->dessiner(pWindow);
	pTableauDeBord->dessiner(pWindow);

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
			if ((event.mouseButton.x>710)&&(event.mouseButton.x<745)&&(event.mouseButton.y<335)&&(event.mouseButton.y>300)){
				typeTourChoisi = 1;
			}
			else if ((event.mouseButton.x>760)&&(event.mouseButton.x<795)&&(event.mouseButton.y<335)&&(event.mouseButton.y>300)){
				typeTourChoisi = 0;
			}
			else {
				switch(typeTourChoisi){
					case 0:{
						Coordonnees coordonneesTour((int)event.mouseButton.x,(int)event.mouseButton.y);
						TourAttaqueBasique* ptourTest = new TourAttaqueBasique(100,coordonneesTour,1);
						manager->addTour((Tour*) ptourTest);}
						break;
					case 1:{
						Coordonnees coordonneesTour((int)event.mouseButton.x,(int)event.mouseButton.y);
						CanonLourd* ptourTest = new CanonLourd(100,coordonneesTour,1);
						manager->addTour((Tour*) ptourTest);}
						break;
				}
			}

			
		}
	}
}

EtatJeu::~EtatJeu() {
	// TODO Auto-generated destructor stub
}

