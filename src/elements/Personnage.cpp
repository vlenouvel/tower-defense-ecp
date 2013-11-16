/*
 * Personnage.cpp
 *
 *  TowerDefense ECP
 *       
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
			// TODO : Supprimer le vrai projo de la m�moire ...
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
	cout << "check1" << endl;
	//on initialise la liste qui va contenir la suite de case a analyser avec la case d'entree
	multimap<int,Case*> listeAParcourir;
	multimap<int,Case*>::iterator myIterator;
	cout << "check1.1" << endl;
	Case * pEntree = pCarte->imageCarte[(int)floor((float)coordonnees.getPosX()/40)][(int)floor((float)coordonnees.getPosY()/40)];
	Case * pSortie = pCarte->pCaseSortie;
	cout << coordonnees.getPosX() << endl;
	cout << coordonnees.getPosY() << endl;
	cout << "check1.2" << endl;
	cout << pEntree->heuristique << endl;
	listeAParcourir.insert(pair<int,Case*>(pEntree->heuristique,pEntree));
	cout << "check2" << endl;
	//boucle principale de l'algo. L'algo s'arrete dans deux cas : soit on atteint la sortie, soit on ne l'atteint pas et dans ce cas, 
	//la liste a parcourir est vide
	int X;
	int Y;
	while (!listeAParcourir.empty()){

		//for (int i=0; i <sizeof(listeAParcourir);i++){

		myIterator = listeAParcourir.begin();
		X = (int)floor((float)(myIterator->second)->coordonneesCase.getPosX()/40);
		Y = (int)floor((float)(myIterator->second)->coordonneesCase.getPosY()/40);
		pCarte->imageCarte[X][Y]->caseParcourue = true;
		cout << X << "     " << Y << endl;
		//on etudie le nord, le sud, l'ouest et l'est par rapport � X,Y
		//nord
		cout << "check2.2" << endl;
		if (((pCarte->imageCarte[X][Y-1])->caseParcourue == false) && ((pCarte->imageCarte[X][Y-1])->caseOccupee == false)&&(Y>0)){
			cout << "check nord 1" << endl;
			if (((pCarte->imageCarte[X][Y-1])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())&&((pCarte->imageCarte[X][Y-1])->coordonneesCase.getPosY() == pSortie->coordonneesCase.getPosY())){
				cout << "pas possible" << endl;
				return true;
			}
			cout << "check nord 1.1" << endl;
			(pCarte->imageCarte[X][Y-1])->distanceEntree = abs((int)floor((float)(pCarte->imageCarte[X][Y-1])->coordonneesCase.getPosX()/40)-(int)floor((float)(pEntree->coordonneesCase).getPosX()/40)) + abs((int)floor((float)(pCarte->imageCarte[X][Y-1])->coordonneesCase.getPosY()/40)-(int)floor((float)(pEntree->coordonneesCase).getPosY()/40));
			cout << (pCarte->imageCarte[X][Y-1])->distanceEntree << endl;
			(pCarte->imageCarte[X][Y-1])->caseParcourue = true;
			cout << (pCarte->imageCarte[X][Y-1])->caseParcourue << endl;
			cout << (pCarte->imageCarte[X][Y-1])->distanceEntree + (pCarte->imageCarte[X][Y-1])->heuristique << endl;
			listeAParcourir.insert(pair<int,Case*>((pCarte->imageCarte[X][Y-1])->distanceEntree + (pCarte->imageCarte[X][Y-1])->heuristique,pCarte->imageCarte[X][Y-1]));
			cout << "check nord 1.4" << endl;
		}
		//sud
		if (((pCarte->imageCarte[X][Y+1])->caseParcourue == false) && ((pCarte->imageCarte[X][Y+1])->caseOccupee == false)&&(Y<sizeof(pCarte->imageCarte))){
			cout << "check sud 1" << endl;
			if (((pCarte->imageCarte[X][Y+1])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())&&((pCarte->imageCarte[X][Y+1])->coordonneesCase.getPosY() == pSortie->coordonneesCase.getPosY())){
				cout << "pas possible" << endl;
				return true;
			}
			cout << "check sud 1.1" << endl;
			(pCarte->imageCarte[X][Y+1])->distanceEntree = abs((int)floor((float)(pCarte->imageCarte[X][Y+1])->coordonneesCase.getPosX()/40)-(int)floor((float)(pEntree->coordonneesCase).getPosX()/40)) + abs((int)floor((float)(pCarte->imageCarte[X][Y+1])->coordonneesCase.getPosY()/40)-(int)floor((float)(pEntree->coordonneesCase).getPosY()/40));
			cout << "check sud 1.2" << endl;
			(pCarte->imageCarte[X][Y+1])->caseParcourue = true;
			cout << "check sud 1.3" << endl;
			listeAParcourir.insert(pair<int,Case*>((pCarte->imageCarte[X][Y+1])->distanceEntree + (pCarte->imageCarte[X][Y+1])->heuristique,(pCarte->imageCarte[X][Y+1])));
			cout << "check sud 1.4" << endl;
		}
		//ouest
		if (((pCarte->imageCarte[X-1][Y])->caseParcourue == false) && ((pCarte->imageCarte[X-1][Y])->caseOccupee == false)&&(X>0)){
			cout << "check ouest 1" << endl;
			if (((pCarte->imageCarte[X-1][Y])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())&&((pCarte->imageCarte[X-1][Y])->coordonneesCase.getPosY() == pSortie->coordonneesCase.getPosY())){
				cout << "pas possible" << endl;
				return true;
			}
			cout << "check ouest 1.1" << endl;
			(pCarte->imageCarte[X-1][Y])->distanceEntree = abs((int)floor((float)(pCarte->imageCarte[X-1][Y])->coordonneesCase.getPosX()/40)-(int)floor((float)(pEntree->coordonneesCase).getPosX()/40)) + abs((int)floor((float)(pCarte->imageCarte[X-1][Y])->coordonneesCase.getPosY()/40)-(int)floor((float)(pEntree->coordonneesCase).getPosY()/40));
			cout << "check ouest 1.2" << endl;
			(pCarte->imageCarte[X-1][Y])->caseParcourue = true;
			cout << "check ouest 1.3" << endl;
			listeAParcourir.insert(pair<int,Case*>((pCarte->imageCarte[X-1][Y])->distanceEntree + (pCarte->imageCarte[X-1][Y])->heuristique,(pCarte->imageCarte[X-1][Y])));
			cout << "check ouest 1.4" << endl;
		}
		//est
		if (((pCarte->imageCarte[X+1][Y])->caseParcourue == false) && ((pCarte->imageCarte[X+1][Y])->caseOccupee == false)&&(X<sizeof(pCarte->imageCarte[0]))){
			cout << "check est 1" << endl;
			if (((pCarte->imageCarte[X+1][Y])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())&&((pCarte->imageCarte[X+1][Y])->coordonneesCase.getPosY() == pSortie->coordonneesCase.getPosY())){
				cout << "pas posible" << endl;
				return true;
			}
			cout << "check est 1.1" << endl;
			(pCarte->imageCarte[X+1][Y])->distanceEntree = abs((int)floor((float)(pCarte->imageCarte[X+1][Y])->coordonneesCase.getPosX())-(int)floor((float)(pEntree->coordonneesCase).getPosX()/40)) + abs((int)floor((float)(pCarte->imageCarte[X+1][Y])->coordonneesCase.getPosY()/40)-(int)floor((float)(pEntree->coordonneesCase).getPosY()/40));
			cout << "check est 1.2" << endl;
			(pCarte->imageCarte[X+1][Y])->caseParcourue = true;
			cout << "check est 1.3" << endl;
			listeAParcourir.insert(pair<int,Case*>((pCarte->imageCarte[X+1][Y])->distanceEntree + (pCarte->imageCarte[X+1][Y])->heuristique,(pCarte->imageCarte[X+1][Y])));
			cout << "check est 1.4" << endl;
		}
		cout << "check3" << endl;
		listeAParcourir.erase(myIterator);
	}
	cout << "bad very bad" << endl;
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

