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
	pTableauDeBord = new TableauDeBord();
	manager->addCarte(carte);



	typeTourChoisi = 1;
	Coordonnees coordonneesPersonnage(200,200);
	pPersonnage = new Personnage(1,1,1,coordonneesPersonnage);
	manager->addPersonnage(pPersonnage);
	pApp = tApp;
	//Creation du generateur de vague
	pGenerateur = new GenerateurVague(tApp->horloge.getElapsedTime());

}

void EtatJeu::dessiner(sf::RenderWindow &pWindow){

	ResourceManager* manager = ResourceManager::getInstance();

	carte->dessiner(pWindow);
	pRessources->dessiner(pWindow);
	pTableauDeBord->dessiner(pWindow);

	vector<Tour*> tourConteneur = manager->getTour();

	if (!tourConteneur.empty()){
		for(int i=0;i<tourConteneur.size();i++){
			tourConteneur[i]->dessiner(pWindow);
		}
	}
	vector<Personnage*> personnageConteneur = manager->getPersonnage();
	if (!personnageConteneur.empty()){
		for(int i=0;i<personnageConteneur.size();++i){
			personnageConteneur[i]->dessiner(pWindow);
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
						TourAttaqueBasique* ptourTest = new TourAttaqueBasique(100,coordonneesTour);
						manager->addTour((Tour*) ptourTest);}
						break;
					case 1:{
						Coordonnees coordonneesTour((int)event.mouseButton.x,(int)event.mouseButton.y);
						CanonLourd* ptourTest = new CanonLourd(100,coordonneesTour);
						manager->addTour((Tour*) ptourTest);}
						break;
				}
			}

			
		}
	}
}

void EtatJeu::agir() {
	pGenerateur->genererVague(pApp->horloge.getElapsedTime());

}

EtatJeu::~EtatJeu() {
	// TODO Auto-generated destructor stub
}

