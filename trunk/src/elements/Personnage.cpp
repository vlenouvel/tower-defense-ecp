/*
 * Personnage.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "Personnage.h"


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
	int actuelleAbscisse = coordonnees.getPosX();
	coordonnees.setPosX(actuelleAbscisse + vitesse);
	if(coordonnees.getPosX() > 800)
		coordonnees.setPosX(0);
	spritePersonnage.setPosition(coordonnees.posX,coordonnees.posY);
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

pair <bool,vector<Case *>> Personnage::trouverChemin(Carte * pCarte){
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
		if (((pCarte->imageCarte[X][Y-1])->caseParcourue == false) && ((pCarte->imageCarte[X][Y-1])->caseOccupee == 0)){
			if (((pCarte->imageCarte[X][Y-1])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())&&((pCarte->imageCarte[X][Y-1])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())){
				return make_pair(true,chemin);
			}
			(pCarte->imageCarte[X][Y-1])->distanceEntree = abs((pCarte->imageCarte[X][Y-1])->coordonneesCase.getPosX()- (pEntree->coordonneesCase).getPosX()) + abs((pCarte->imageCarte[X][Y-1])->coordonneesCase.getPosY()- (pEntree->coordonneesCase).getPosY());
			(pCarte->imageCarte[X][Y-1])->caseParcourue = true;
			listeAParcourir.insert(pair<int,Case*>((pCarte->imageCarte[X][Y-1])->distanceEntree + (pCarte->imageCarte[X][Y-1])->heuristique,(pCarte->imageCarte[X][Y-1])));
		}
		//sud
		if (((pCarte->imageCarte[X][Y+1])->caseParcourue == false) && ((pCarte->imageCarte[X][Y+1])->caseOccupee == 0)){
			if (((pCarte->imageCarte[X][Y+1])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())&&((pCarte->imageCarte[X][Y+1])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())){
				return make_pair(true,chemin);
			}
			(pCarte->imageCarte[X][Y+1])->distanceEntree = abs((pCarte->imageCarte[X][Y+1])->coordonneesCase.getPosX()- (pEntree->coordonneesCase).getPosX()) + abs((pCarte->imageCarte[X][Y+1])->coordonneesCase.getPosY()- (pEntree->coordonneesCase).getPosY());
			(pCarte->imageCarte[X][Y+1])->caseParcourue = true;
			listeAParcourir.insert(pair<int,Case*>((pCarte->imageCarte[X][Y+1])->distanceEntree + (pCarte->imageCarte[X][Y+1])->heuristique,(pCarte->imageCarte[X][Y+1])));
		}
		//ouest
		if (((pCarte->imageCarte[X-1][Y])->caseParcourue == false) && ((pCarte->imageCarte[X-1][Y])->caseOccupee == 0)){
			if (((pCarte->imageCarte[X-1][Y])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())&&((pCarte->imageCarte[X-1][Y])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())){
				return make_pair(true,chemin);
			}
			(pCarte->imageCarte[X-1][Y])->distanceEntree = abs((pCarte->imageCarte[X-1][Y])->coordonneesCase.getPosX()- (pEntree->coordonneesCase).getPosX()) + abs((pCarte->imageCarte[X-1][Y])->coordonneesCase.getPosY()- (pEntree->coordonneesCase).getPosY());
			(pCarte->imageCarte[X-1][Y])->caseParcourue = true;
			listeAParcourir.insert(pair<int,Case*>((pCarte->imageCarte[X-1][Y])->distanceEntree + (pCarte->imageCarte[X-1][Y])->heuristique,(pCarte->imageCarte[X-1][Y])));
		}
		//est
		if (((pCarte->imageCarte[X+1][Y])->caseParcourue == false) && ((pCarte->imageCarte[X+1][Y])->caseOccupee == 0)){
			if (((pCarte->imageCarte[X+1][Y])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())&&((pCarte->imageCarte[X+1][Y])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())){
				return make_pair(true,chemin);
			}
			(pCarte->imageCarte[X+1][Y])->distanceEntree = abs((pCarte->imageCarte[X+1][Y])->coordonneesCase.getPosX()- (pEntree->coordonneesCase).getPosX()) + abs((pCarte->imageCarte[X+1][Y])->coordonneesCase.getPosY()- (pEntree->coordonneesCase).getPosY());
			(pCarte->imageCarte[X+1][Y])->caseParcourue = true;
			listeAParcourir.insert(pair<int,Case*>((pCarte->imageCarte[X+1][Y])->distanceEntree + (pCarte->imageCarte[X+1][Y])->heuristique,(pCarte->imageCarte[X+1][Y])));
		}
		listeAParcourir.erase(myIterator);
	}
	return make_pair(false,NULL);
}
