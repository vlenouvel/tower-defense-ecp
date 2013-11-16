/*
 * Personnage.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "Personnage.h"
#include <cmath>

Personnage::Personnage(int tVie, int tVitesse, int tArmure, Coordonnees tCoord) :
		vie(tVie), vitesse(tVitesse), armure(tArmure), coordonnees(tCoord)
{
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	texturePersonnage = pResourcesLoader->texturePersonnage;
	spritePersonnage.setTexture(texturePersonnage);
	spritePersonnage.setScale(0.5,0.5);
	spritePersonnage.setPosition(tCoord.posX,tCoord.posY);
}

void Personnage::agir()
{
	this->avancer();
}

void Personnage::avancer()
{
	if(!chemin.empty()){
		float imageVitesse = (float)vitesse;
		while (imageVitesse > 0){
			int abscisseCible = chemin[0]->coordonneesCase.getPosX();
			int ordonneeCible = chemin[0]->coordonneesCase.getPosY();
			int abscissePerso = coordonnees.getPosX();
			int ordonneePerso = coordonnees.getPosY();
			float distanceCiblePerso = (pow((float)abscisseCible - abscissePerso,2) + pow((float)ordonneeCible - ordonneePerso,2));
			if (distanceCiblePerso < vitesse){
				coordonnees.setPosX((int)floor((abscisseCible - abscissePerso)/sqrt(distanceCiblePerso)));
				coordonnees.setPosX((int)floor((ordonneeCible - ordonneePerso)/sqrt(distanceCiblePerso)));
				imageVitesse = 0;
			}
			else{
				float distanceRestante = (float)vitesse - distanceCiblePerso;
				chemin.erase(chemin.begin());
				imageVitesse = imageVitesse - distanceCiblePerso;
			}
		}
		spritePersonnage.setPosition(coordonnees.posX,coordonnees.posY);
	}
	else
		mourir();
}

void Personnage::perdrePV(int degat)
{
	if(degat > armure){
		vie -= (degat - armure);
		if(vie <= 0)
		{
			this->mourir();
		}
	}
}

void Personnage::mourir()
{
	ResourceManager *manager = ResourceManager::getInstance();
	manager->removePersonnage(this);

	// Also remove all projectiles going for that personnage
	std::vector<Projectile*> projectileConteneur = manager->getProjectile();
	vector<Projectile*>::iterator projectileIterator;
	for(projectileIterator = projectileConteneur.begin() ; projectileIterator!= projectileConteneur.end() ; projectileIterator++)
	{
		Projectile* pProjo = *projectileIterator;
		if(pProjo->getCible() == this)
		{
			manager->removeProjectile(pProjo);
			// TODO : Supprimer le vrai projo de la mémoire ...
			//delete pProjo;
			pProjo->setCible(0);
		}
	}
	delete this;
}

Personnage::~Personnage() {
	// TODO Auto-generated destructor stub
}

void Personnage::dessiner(sf::RenderWindow &pWindow){
	pWindow.draw(spritePersonnage);
}

int Personnage::getVie()
{
	return this->vie;
}

Coordonnees Personnage::getCoordonnees()
{
	return this->coordonnees;
}

// Cette fonction retourne une pair
bool Personnage::trouverChemin(Carte * pCarte){
	//on initialise la liste qui va contenir la suite de case a analyser avec la case d'entree
	multimap<int,Case*> listeAParcourir;
	multimap<int,Case*>::iterator myIterator;
	Case * pEntree = pCarte->imageCarte[coordonnees.getPosX()][coordonnees.getPosY()];
	Case * pSortie = pCarte->imageCarte[20][1];
	listeAParcourir.insert(pair<int,Case*>(pEntree->heuristique,pEntree));

	//boucle principale de l'algo. L'algo s'arrete dans deux cas : soit on atteint la sortie, soit on ne l'atteint pas et dans ce cas,
	//la liste a parcourir est vide
	int X;
	int Y;
	while (!listeAParcourir.empty()){
		myIterator = listeAParcourir.begin();
		X = (myIterator->second)->coordonneesCase.getPosX();
		Y = (myIterator->second)->coordonneesCase.getPosY();
		//on etudie le nord, le sud, l'ouest et l'est par rapport à X,Y
		//nord
		if (((pCarte->imageCarte[X][Y-1])->caseParcourue == false) && ((pCarte->imageCarte[X][Y-1])->caseOccupee == false)){
			if (((pCarte->imageCarte[X][Y-1])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())&&((pCarte->imageCarte[X][Y-1])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())){
				return true;
			}
			(pCarte->imageCarte[X][Y-1])->distanceEntree = abs((pCarte->imageCarte[X][Y-1])->coordonneesCase.getPosX()- (pEntree->coordonneesCase).getPosX()) + abs((pCarte->imageCarte[X][Y-1])->coordonneesCase.getPosY()- (pEntree->coordonneesCase).getPosY());
			(pCarte->imageCarte[X][Y-1])->caseParcourue = true;
			listeAParcourir.insert(pair<int,Case*>((pCarte->imageCarte[X][Y-1])->distanceEntree + (pCarte->imageCarte[X][Y-1])->heuristique,(pCarte->imageCarte[X][Y-1])));
		}
		//sud
		if (((pCarte->imageCarte[X][Y+1])->caseParcourue == false) && ((pCarte->imageCarte[X][Y+1])->caseOccupee == false)){
			if (((pCarte->imageCarte[X][Y+1])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())&&((pCarte->imageCarte[X][Y+1])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())){
				return true;
			}
			(pCarte->imageCarte[X][Y+1])->distanceEntree = abs((pCarte->imageCarte[X][Y+1])->coordonneesCase.getPosX()- (pEntree->coordonneesCase).getPosX()) + abs((pCarte->imageCarte[X][Y+1])->coordonneesCase.getPosY()- (pEntree->coordonneesCase).getPosY());
			(pCarte->imageCarte[X][Y+1])->caseParcourue = true;
			listeAParcourir.insert(pair<int,Case*>((pCarte->imageCarte[X][Y+1])->distanceEntree + (pCarte->imageCarte[X][Y+1])->heuristique,(pCarte->imageCarte[X][Y+1])));
		}
		//ouest
		if (((pCarte->imageCarte[X-1][Y])->caseParcourue == false) && ((pCarte->imageCarte[X-1][Y])->caseOccupee == false)){
			if (((pCarte->imageCarte[X-1][Y])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())&&((pCarte->imageCarte[X-1][Y])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())){
				return true;
			}
			(pCarte->imageCarte[X-1][Y])->distanceEntree = abs((pCarte->imageCarte[X-1][Y])->coordonneesCase.getPosX()- (pEntree->coordonneesCase).getPosX()) + abs((pCarte->imageCarte[X-1][Y])->coordonneesCase.getPosY()- (pEntree->coordonneesCase).getPosY());
			(pCarte->imageCarte[X-1][Y])->caseParcourue = true;
			listeAParcourir.insert(pair<int,Case*>((pCarte->imageCarte[X-1][Y])->distanceEntree + (pCarte->imageCarte[X-1][Y])->heuristique,(pCarte->imageCarte[X-1][Y])));
		}
		//est
		if (((pCarte->imageCarte[X+1][Y])->caseParcourue == false) && ((pCarte->imageCarte[X+1][Y])->caseOccupee == false)){
			if (((pCarte->imageCarte[X+1][Y])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())&&((pCarte->imageCarte[X+1][Y])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())){
				return true;
			}
			(pCarte->imageCarte[X+1][Y])->distanceEntree = abs((pCarte->imageCarte[X+1][Y])->coordonneesCase.getPosX()- (pEntree->coordonneesCase).getPosX()) + abs((pCarte->imageCarte[X+1][Y])->coordonneesCase.getPosY()- (pEntree->coordonneesCase).getPosY());
			(pCarte->imageCarte[X+1][Y])->caseParcourue = true;
			listeAParcourir.insert(pair<int,Case*>((pCarte->imageCarte[X+1][Y])->distanceEntree + (pCarte->imageCarte[X+1][Y])->heuristique,(pCarte->imageCarte[X+1][Y])));
		}
		listeAParcourir.erase(myIterator);
	}
	return false;
}

void Personnage::ecrireChemin(Carte * pCarte){
	//maintenant que carteRecherche est remplie, on definit le chemin a prendre
	chemin.clear();
	Case * trace;
	trace = pCarte->pCaseSortie;
	int distanceEntree;
	while ((trace->coordonneesCase.getPosX() != coordonnees.getPosX())&&(trace->coordonneesCase.getPosY() != coordonnees.getPosY())){
		cheminIterator = chemin.begin();
		chemin.insert(cheminIterator, trace);
		if ((pCarte->imageCarte[trace->coordonneesCase.getPosX()][trace->coordonneesCase.getPosY() - 1]->distanceEntree == (pCarte->imageCarte[trace->coordonneesCase.getPosX()][trace->coordonneesCase.getPosY()]->distanceEntree - 1))&&(pCarte->imageCarte[trace->coordonneesCase.getPosX()][trace->coordonneesCase.getPosY() - 1]->caseParcourue == true)){
			trace = pCarte->imageCarte[trace->coordonneesCase.getPosX()][trace->coordonneesCase.getPosY() - 1];
		}
		else if ((pCarte->imageCarte[trace->coordonneesCase.getPosX()][trace->coordonneesCase.getPosY() + 1]->distanceEntree == (pCarte->imageCarte[trace->coordonneesCase.getPosX()][trace->coordonneesCase.getPosY()]->distanceEntree - 1))&&(pCarte->imageCarte[trace->coordonneesCase.getPosX()][trace->coordonneesCase.getPosY() + 1]->caseParcourue == true)){
			trace = pCarte->imageCarte[trace->coordonneesCase.getPosX()][trace->coordonneesCase.getPosY() + 1];
		}
		else if ((pCarte->imageCarte[trace->coordonneesCase.getPosX() - 1][trace->coordonneesCase.getPosY()]->distanceEntree == (pCarte->imageCarte[trace->coordonneesCase.getPosX()][trace->coordonneesCase.getPosY()]->distanceEntree - 1))&&(pCarte->imageCarte[trace->coordonneesCase.getPosX() - 1][trace->coordonneesCase.getPosY()]->caseParcourue == true)){
			trace = pCarte->imageCarte[trace->coordonneesCase.getPosX() - 1][trace->coordonneesCase.getPosY()];
		}
		else if ((pCarte->imageCarte[trace->coordonneesCase.getPosX() + 1][trace->coordonneesCase.getPosY()]->distanceEntree == (pCarte->imageCarte[trace->coordonneesCase.getPosX()][trace->coordonneesCase.getPosY()]->distanceEntree - 1))&&(pCarte->imageCarte[trace->coordonneesCase.getPosX() + 1][trace->coordonneesCase.getPosY()]->caseParcourue == true)){
			trace = pCarte->imageCarte[trace->coordonneesCase.getPosX() + 1][trace->coordonneesCase.getPosY()];
		}
	}
	for (int i = 0; i<sizeof(pCarte->imageCarte); i++)
		for (int j = 0; j<sizeof(pCarte->imageCarte[0]); i++)
			pCarte->imageCarte[i][j]->caseParcourue = false;
}

