/*
 * EtatJeu.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "EtatJeu.h"
#include <iostream>
#include "../elements/Personnage.h"
#include <cmath>
using namespace std;

EtatJeu::EtatJeu(App *tApp) : Etat(tApp), pApp(tApp) {
	ResourceManager* manager = ResourceManager::getInstance();

	// Creation de la carte
	carte = new Carte();
	pRessources = new Ressources();
	pTableauDeBord = new TableauDeBord();
	manager->addCarte(carte);



	typeTourChoisi = 0;
	Coordonnees coordonneesPersonnage(200,200);
	pPersonnage = new Personnage(1,1,1,coordonneesPersonnage);
	manager->addPersonnage(pPersonnage);
	//Creation du generateur de vague
	GenerateurVague* pGenerateur = new GenerateurVague();
	manager->addGenerateurVague(pGenerateur);

}

void EtatJeu::dessiner(sf::RenderWindow &pWindow){

	ResourceManager* manager = ResourceManager::getInstance();

	carte->dessiner(pWindow);
	pRessources->dessiner(pWindow);
	pTableauDeBord->dessiner(pWindow);

	vector<Tour*> tourConteneur = manager->getTour();

	if (!tourConteneur.empty()){
		for(unsigned int i=0;i<tourConteneur.size();i++){
			tourConteneur[i]->dessiner(pWindow);
		}
	}
	vector<Personnage*> personnageConteneur = manager->getPersonnage();
	if (!personnageConteneur.empty()){
		for(unsigned int i=0;i<personnageConteneur.size();++i){
			personnageConteneur[i]->dessiner(pWindow);
		}
	}

	vector<Projectile*> projectileConteneur = manager->getProjectile();
	if (!projectileConteneur.empty()){
		for(unsigned int i=0;i<projectileConteneur.size();++i){
			projectileConteneur[i]->dessiner(pWindow);
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
				cout << "check1" << endl;
				Coordonnees coordonneesTour((int)event.mouseButton.x,(int)event.mouseButton.y);
				bool autorisation = true;
				if (!manager->getPersonnage().empty()){
					for (int i=0; i< (manager->getPersonnage()).size();i++){
						autorisation = (manager->getPersonnage())[i]->trouverChemin(manager->getCarte());
						if (autorisation == false)
							break;
					}
				}
				cout << "check2" << endl;
				if (autorisation == true){
					switch(typeTourChoisi){
						case 0:{
							TourAttaqueBasique* ptourTest = new TourAttaqueBasique(100,coordonneesTour);
							manager->addTour((Tour*) ptourTest);}
							break;
						case 1:{
							CanonLourd* ptourTest = new CanonLourd(100,coordonneesTour);
							manager->addTour((Tour*) ptourTest);}
							break;
					}
					cout << "check3" << endl;
					int a = (int)floor((float)coordonneesTour.getPosX()/40);
					cout << a << endl;
					int b = (int)floor((float)coordonneesTour.getPosY()/40);
					cout << b << endl;
					(manager->getCarte())->imageCarte[a][b]->caseOccupee = true;
					cout << "check4" << endl;
					if (!(manager->getPersonnage()).empty()){
						for (int i=0; i< (manager->getPersonnage()).size();i++){
							(manager->getPersonnage())[i]->ecrireChemin(manager->getCarte());
						}
					}
					cout << "check5" << endl;
				}
			}
		}
	}
}

void EtatJeu::agir() {

	ResourceManager *manager = ResourceManager::getInstance();

	GenerateurVague *pGenerateurVague = manager->getGenerateurVague();
	if(pGenerateurVague != 0)
	{
		pGenerateurVague->agir();
	}

	Vague *pVague = manager->getVague();
	if(pVague != 0)
	{
		pVague->agir();
	}

	vector<Tour*> tourConteneur = manager->getTour();
	if (!tourConteneur.empty()){
		for(unsigned int i=0;i<tourConteneur.size();i++){
			tourConteneur[i]->agir();
		}
	}

	vector<Personnage*> personnageConteneur = manager->getPersonnage();
	if (!personnageConteneur.empty()){
		for(unsigned int i=0;i<personnageConteneur.size();++i){
			personnageConteneur[i]->agir();
		}
	}

	vector<Projectile*> projectileConteneur = manager->getProjectile();
	if (!projectileConteneur.empty()){
		for(unsigned int i=0;i<projectileConteneur.size();++i){
			projectileConteneur[i]->agir();
		}
	}
}

EtatJeu::~EtatJeu() {
	// TODO Auto-generated destructor stub
}

