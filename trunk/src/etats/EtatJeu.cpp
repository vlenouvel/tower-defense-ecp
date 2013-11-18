/*
 * EtatJeu.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "EtatJeu.h"
#include <iostream>
#include "../elements/Personnage.h"
#include <cmath>
#include "EtatMort.h"

using namespace std;

EtatJeu::EtatJeu(App *tApp) : Etat(tApp), pApp(tApp) {
	ResourceManager* manager = ResourceManager::getInstance();

	//manager->addEtatJeu(this);

	// Creation de la carte
	carte = new Carte();
	pTableauDeBord = new TableauDeBord();
	manager->addCarte(carte);

	pRessources = new Ressources(this);
	manager->addRessources(pRessources);

	typeTourChoisi = 0;


	//Creation du generateur de vague
	GenerateurVague* pGenerateur = new GenerateurVague();
	manager->addGenerateurVague(pGenerateur);

	arriveCase.setSize(sf::Vector2f(40, 40));
	arriveCase.setPosition(680,560);
	arriveCase.setFillColor(sf::Color::Red);

	tempsDisparitionErreur = sf::seconds((float)1);


	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();

	erreur = "";
	font = pResourcesLoader->police;
	texteErreur.setFont(font);
	texteErreur.setCharacterSize(16);
	texteErreur.setColor(sf::Color::Red);
	texteErreur.setStyle(sf::Text::Bold);
	texteErreur.setPosition(200,250);

}

void EtatJeu::setErreur(string erreurMsg) {

	erreur = erreurMsg;
	tempsErreur = pApp->horloge.getElapsedTime();
}

void EtatJeu::dessiner(sf::RenderWindow &pWindow){

	ResourceManager* manager = ResourceManager::getInstance();

	carte->dessiner(pWindow);
	manager->getGenerateurVague()->dessiner(pWindow);
	pRessources->dessiner(pWindow);
	pTableauDeBord->dessiner(pWindow);

	pWindow.draw(arriveCase);

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

	texteErreur.setString(erreur);
	if(pApp->horloge.getElapsedTime() - tempsErreur < tempsDisparitionErreur) {
		pWindow.draw(texteErreur);
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
			else if((event.mouseButton.x>680)&&(event.mouseButton.y>560)) {
				setErreur("Vous ne pouvez pas construire sur la sortie !");
			}
			else if ((event.mouseButton.x<700)){

				bool autorisation = true;
				int a = (int)floor((float)event.mouseButton.x/40);
				int b = (int)floor((float)event.mouseButton.y/40);
				bool caseEstOccupee = (manager->getCarte())->imageCarte[a][b]->caseOccupee;
				(manager->getCarte())->imageCarte[a][b]->caseOccupee = true;
				if (!manager->getPersonnage().empty()){
					for (unsigned int i=0; i< manager->getPersonnage().size();i++){
						autorisation = ((manager->getPersonnage())[i])->trouverChemin(manager->getCarte());
						manager->getCarte()->nettoyerCarte();
						if (autorisation == false){
							break;
						}
					}
				}
				if(autorisation == false) {
					setErreur("Vous ne pouvez pas bloquer le passage des ennemis !");
				}
				if(caseEstOccupee) {
					//setErreur("Il y a deja une tour sur cette case");
					//caseSelectionnee = (manager->getCarte())->imageCarte[a][b];
					vector<Tour*> tourConteneur = manager->getTour();
					for (unsigned int i=0; i<tourConteneur.size(); i++)
					{
						int coordXTour = tourConteneur[i]->getCoordonnees().getPosX();
						int coordYTour = tourConteneur[i]->getCoordonnees().getPosX();
						if ((coordXTour == 40*a + 20)&&(coordYTour == 40*b + 20))
						{
							manager->setTourSelectionnee(tourConteneur[i]);
						}
					}

				}
				// TODO Mettre les bons prix de tours
				if ((autorisation == true)&&(!caseEstOccupee)){
					Coordonnees coordonneesTour(40*a+20,40*b+20);
					switch(typeTourChoisi){
						case 0:{
							int prix = 10;
							if(Batiment::verifierAchat(prix)) {
								TourAttaqueBasique* ptourTest = new TourAttaqueBasique(prix,coordonneesTour);
								manager->addTour((Tour*) ptourTest);
							}
							else {
								setErreur("Pas assez d'argent !");
							}
							break;
						}
						case 1:{
							int prix = 50;
							if(Batiment::verifierAchat(prix)) {
								CanonLourd* ptourTest = new CanonLourd(prix,coordonneesTour);
								manager->addTour((Tour*) ptourTest);
							}
							else {
								setErreur("Pas assez d'argent !");
							}
							break;
						}
					}
					if (!(manager->getPersonnage()).empty()){
						for (unsigned int i=0; i< (manager->getPersonnage()).size();i++){
							manager->getPersonnage()[i]->trouverChemin(manager->getCarte());
							manager->getPersonnage()[i]->ecrireChemin(manager->getCarte());
						}
					}
				}
				else if (caseEstOccupee){
				}
				else
					(manager->getCarte())->imageCarte[a][b]->caseOccupee = false;
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


	if(manager->getRessources()->getVie() < 1) {

		EtatMort* etatmort = new EtatMort(pApp);
		cout << "Vous avez perdu !" << endl;
		pApp->changerEtat(etatmort);
	}

}


EtatJeu::~EtatJeu() {
	// TODO Auto-generated destructor stub
}

