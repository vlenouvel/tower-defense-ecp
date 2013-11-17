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

	cout << "PERSO CREE" << this << endl;
}

void Personnage::agir()
{
	this->avancer();
}

void Personnage::avancer()
{
	cout << "AVANCER" << this << endl;
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
	else {
		mourir();
	}
}

void Personnage::perdrePV(int degat)
{
	cout << "PERDRE PV" << this << endl;

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
	cout << "MOURIR" << this << endl;

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

	// TODO Changer gain cible tuee
	manager->getRessources()->gagnerArgent(vie);

	delete this;

}



void Personnage::arriver() {

	ResourceManager *manager = ResourceManager::getInstance();

	manager->getRessources()->perdreVie();

}

Personnage::~Personnage() {
	// TODO Auto-generated destructor stub
}

void Personnage::dessiner(sf::RenderWindow &pWindow){

	pWindow.draw(spritePersonnage);
	cout << "DESSINER" << this << endl;

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
	cout << "TROUVERPATH" << this << endl;

	//on initialise la liste qui va contenir la suite de case a analyser avec la case d'entree
	multimap<int,Case*> listeAParcourir;
	multimap<int,Case*>::iterator myIterator;
	
	Case * pEntree = pCarte->imageCarte[(int)floor((float)coordonnees.getPosX()/40)][(int)floor((float)coordonnees.getPosY()/40)];
	Case * pSortie = pCarte->pCaseSortie;
	cout << coordonnees.getPosX() << endl;
	cout << coordonnees.getPosY() << endl;
	cout << pEntree->heuristique << endl;
	listeAParcourir.insert(pair<int,Case*>(pEntree->heuristique,pEntree));
	pCarte->imageCarte[(int)floor((float)coordonnees.getPosX()/40)][(int)floor((float)coordonnees.getPosY()/40)]->distanceEntree = 0;
	//boucle principale de l'algo. L'algo s'arrete dans deux cas : soit on atteint la sortie, soit on ne l'atteint pas et dans ce cas, 
	//la liste a parcourir est vide
	int X;
	int Y;
	while (!listeAParcourir.empty()){
		cout << "BOUCLE TROUVER PATH" << endl;
		myIterator = listeAParcourir.begin();
		X = (int)floor((float)(myIterator->second)->coordonneesCase.getPosX()/40);
		Y = (int)floor((float)(myIterator->second)->coordonneesCase.getPosY()/40);
		pCarte->imageCarte[X][Y]->caseParcourue = true;
		cout << "a" << endl;
		//on etudie le nord, le sud, l'ouest et l'est par rapport � X,Y
		//nord
		//abs((int)floor((float)(pCarte->imageCarte[X][Y-1])->coordonneesCase.getPosX()/40)-(int)floor((float)(pEntree->coordonneesCase).getPosX()/40)) + abs((int)floor((float)(pCarte->imageCarte[X][Y-1])->coordonneesCase.getPosY()/40)-(int)floor((float)(pEntree->coordonneesCase).getPosY()/40))
		if (Y>0){
			if (((pCarte->imageCarte[X][Y-1])->caseParcourue == false) && ((pCarte->imageCarte[X][Y-1])->caseOccupee == false)){
				(pCarte->imageCarte[X][Y-1])->distanceEntree = (pCarte->imageCarte[X][Y])->distanceEntree + 1;
				(pCarte->imageCarte[X][Y-1])->caseParcourue = true;
				if (((pCarte->imageCarte[X][Y-1])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())&&((pCarte->imageCarte[X][Y-1])->coordonneesCase.getPosY() == pSortie->coordonneesCase.getPosY())){
					return true;
				}
				listeAParcourir.insert(pair<int,Case*>((pCarte->imageCarte[X][Y-1])->distanceEntree + (pCarte->imageCarte[X][Y-1])->heuristique,pCarte->imageCarte[X][Y-1]));
			}
		}
		cout << "b" << endl;
		//sud
		//if(Y<sizeof(pCarte->imageCarte)){
		if(Y < pCarte->imageCarteY -1) {
			if (((pCarte->imageCarte[X][Y+1])->caseParcourue == false) && ((pCarte->imageCarte[X][Y+1])->caseOccupee == false)){
				(pCarte->imageCarte[X][Y+1])->distanceEntree = (pCarte->imageCarte[X][Y])->distanceEntree + 1;
				(pCarte->imageCarte[X][Y+1])->caseParcourue = true;
				if (((pCarte->imageCarte[X][Y+1])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())&&((pCarte->imageCarte[X][Y+1])->coordonneesCase.getPosY() == pSortie->coordonneesCase.getPosY())){
					return true;
				}
				listeAParcourir.insert(pair<int,Case*>((pCarte->imageCarte[X][Y+1])->distanceEntree + (pCarte->imageCarte[X][Y+1])->heuristique,(pCarte->imageCarte[X][Y+1])));
			}
		}
		cout << "c" << endl;
		//ouest
		if (X>0){
			if (((pCarte->imageCarte[X-1][Y])->caseParcourue == false) && ((pCarte->imageCarte[X-1][Y])->caseOccupee == false)){
				(pCarte->imageCarte[X-1][Y])->distanceEntree = (pCarte->imageCarte[X][Y])->distanceEntree + 1;
				(pCarte->imageCarte[X-1][Y])->caseParcourue = true;
				if (((pCarte->imageCarte[X-1][Y])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())&&((pCarte->imageCarte[X-1][Y])->coordonneesCase.getPosY() == pSortie->coordonneesCase.getPosY())){
					return true;
				}
				listeAParcourir.insert(pair<int,Case*>((pCarte->imageCarte[X-1][Y])->distanceEntree + (pCarte->imageCarte[X-1][Y])->heuristique,(pCarte->imageCarte[X-1][Y])));
			}
		}
		cout << "d" << endl;
		//est
		//if (X<sizeof(pCarte->imageCarte[0])){
		if (X < pCarte->imageCarteX - 1) {
			cout << "d1 - size :" << sizeof(pCarte->imageCarte[0]) << endl;
			cout << "X:" << X << " et Y:" << Y << endl;
			if (((pCarte->imageCarte[X+1][Y])->caseParcourue == false) && ((pCarte->imageCarte[X+1][Y])->caseOccupee == false)){
				cout << "d2" << endl;
				(pCarte->imageCarte[X+1][Y])->distanceEntree = (pCarte->imageCarte[X][Y])->distanceEntree + 1;
				(pCarte->imageCarte[X+1][Y])->caseParcourue = true;
				if (((pCarte->imageCarte[X+1][Y])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())&&((pCarte->imageCarte[X+1][Y])->coordonneesCase.getPosY() == pSortie->coordonneesCase.getPosY())){		
					cout << "d3" << endl;
					return true;
				}
				cout << "d4" << endl;

				listeAParcourir.insert(pair<int,Case*>((pCarte->imageCarte[X+1][Y])->distanceEntree + (pCarte->imageCarte[X+1][Y])->heuristique,(pCarte->imageCarte[X+1][Y])));
			}
		}
		cout << "e" << endl;
		listeAParcourir.erase(myIterator);
	}
	return false;
}

void Personnage::ecrireChemin(Carte * pCarte){
	cout << "ECRIRE CHEMIN" << this << endl;
	//maintenant que carteRecherche est remplie, on definit le chemin a prendre
	chemin.clear();
	Case * trace;
	trace = pCarte->pCaseSortie;
	int distanceEntree;
	int X;
	int Y;
	X = (int)floor((float)trace->coordonneesCase.getPosX()/40);
	Y = (int)floor((float)trace->coordonneesCase.getPosY()/40);
	bool jeton;
	cheminIterator = chemin.begin();
	chemin.insert(cheminIterator, trace);
	cout << "t1" <<endl;
	while ((X != (int)floor((float)coordonnees.getPosX()/40))||(Y != (int)floor((float)coordonnees.getPosY()/40))){
		cout << "t2" << endl;
		cout << "X:" << X << " - Y:" << Y << endl;
		cout << (int)floor((float)coordonnees.getPosX()/40) << "-" << (int)floor((float)coordonnees.getPosY()/40) << endl;
		cheminIterator = chemin.begin();
		jeton = true;
		//nord
		if ((Y>0)&&(jeton == true)){
			if ((pCarte->imageCarte[X][Y - 1]->distanceEntree == (pCarte->imageCarte[X][Y]->distanceEntree - 1))&&(pCarte->imageCarte[X][Y - 1]->caseParcourue == true)){
				trace = pCarte->imageCarte[X][Y - 1];
				jeton = false;
			}
			cout << "nord" << endl;
		}
		//puis sud
		//if((Y<sizeof(pCarte->imageCarte))&&(jeton == true)){
		if((Y < pCarte->imageCarteY - 1)&&(jeton == true)) {
			if ((pCarte->imageCarte[X][Y + 1]->distanceEntree == (pCarte->imageCarte[X][Y]->distanceEntree - 1))&&(pCarte->imageCarte[X][Y + 1]->caseParcourue == true)){
				trace = pCarte->imageCarte[X][Y + 1];
				jeton = false;
			}
			cout << "sud" << endl;
		}
		//puis ouest
		if ((X>0)&&(jeton == true)){
			if ((pCarte->imageCarte[X - 1][Y]->distanceEntree == (pCarte->imageCarte[X][Y]->distanceEntree - 1))&&(pCarte->imageCarte[X - 1][Y]->caseParcourue == true)){
				trace = pCarte->imageCarte[X - 1][Y];
				jeton = false;
			}
			cout << "ouest" << endl;
		}
		//et enfin est
		//if ((X<sizeof(pCarte->imageCarte[0]))&&(jeton == true)){
		if((X < pCarte->imageCarteX - 1)&&(jeton == true)) {
			if ((pCarte->imageCarte[X + 1][Y]->distanceEntree == (pCarte->imageCarte[X][Y]->distanceEntree - 1))&&(pCarte->imageCarte[X + 1][Y]->caseParcourue == true)){
				trace = pCarte->imageCarte[X + 1][Y];
				jeton = false;
			}
			cout << "est" << endl;
		}
		chemin.insert(cheminIterator, trace);
		X = (int)floor((float)trace->coordonneesCase.getPosX()/40);
		Y = (int)floor((float)trace->coordonneesCase.getPosY()/40);
	}
	pCarte->nettoyerCarte();
}


