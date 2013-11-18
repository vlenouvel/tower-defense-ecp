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
	gain = 10;
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	texturePersonnage = pResourcesLoader->texturePersonnage;
	spritePersonnage.setTexture(texturePersonnage);
	spritePersonnage.setScale(0.5,0.5);
	spritePersonnage.setPosition(tCoord.posX,tCoord.posY);

	vieInitial = vie;
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
			int distanceCiblePerso = (int)sqrt((pow((float)abscisseCible - abscissePerso,2) + pow((float)ordonneeCible - ordonneePerso,2)));
			if (distanceCiblePerso > imageVitesse){
				coordonnees.setPosX(abscissePerso+(int)((float)(abscisseCible - abscissePerso)*imageVitesse/distanceCiblePerso+0.5));
				coordonnees.setPosY(ordonneePerso+(int)((float)(ordonneeCible - ordonneePerso)*imageVitesse/distanceCiblePerso+0.5));
				imageVitesse = 0;
			}

			else {
				float distanceRestante = (float)vitesse - distanceCiblePerso;

				// TODO Checker bugfix ici !!
				if (!chemin.empty()) {
					chemin.erase(chemin.begin());
					imageVitesse = distanceRestante;

				}
				else {
					imageVitesse = 0;
				}
			}
		}
		spritePersonnage.setPosition(coordonnees.posX,coordonnees.posY);
	}
	else {
		arriver();
	}
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

	// TODO Changer gain cible tuee
	manager->getRessources()->gagnerArgent(gain);
	manager->getRessources()->augmenterScore(1);
	delete this;

}



void Personnage::arriver() {

	ResourceManager *manager = ResourceManager::getInstance();

	manager->getRessources()->perdreVie();

	/*EtatJeu* etat = (EtatJeu*)manager->getEtatJeu();
	etat->setErreur("Vous avez perdu une vie !");*/
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
			// TODO : Supprimer le vrai projo de la memoire ...
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
	
	Case * pEntree = pCarte->imageCarte[(int)floor((float)coordonnees.getPosX()/40)][(int)floor((float)coordonnees.getPosY()/40)];
	Case * pSortie = pCarte->pCaseSortie;
	listeAParcourir.insert(pair<int,Case*>(pEntree->heuristique,pEntree));
	pCarte->imageCarte[(int)floor((float)coordonnees.getPosX()/40)][(int)floor((float)coordonnees.getPosY()/40)]->distanceEntree = 0;
	//boucle principale de l'algo. L'algo s'arrete dans deux cas : soit on atteint la sortie, soit on ne l'atteint pas et dans ce cas, 
	//la liste a parcourir est vide
	int X;
	int Y;
	while (!listeAParcourir.empty()){
		myIterator = listeAParcourir.begin();
		X = (int)floor((float)(myIterator->second)->coordonneesCase.getPosX()/40);
		Y = (int)floor((float)(myIterator->second)->coordonneesCase.getPosY()/40);
		pCarte->imageCarte[X][Y]->caseParcourue = true;
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
		//est
		//if (X<sizeof(pCarte->imageCarte[0])){
		if (X < pCarte->imageCarteX - 1) {
			if (((pCarte->imageCarte[X+1][Y])->caseParcourue == false) && ((pCarte->imageCarte[X+1][Y])->caseOccupee == false)){
				(pCarte->imageCarte[X+1][Y])->distanceEntree = (pCarte->imageCarte[X][Y])->distanceEntree + 1;
				(pCarte->imageCarte[X+1][Y])->caseParcourue = true;
				if (((pCarte->imageCarte[X+1][Y])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())&&((pCarte->imageCarte[X+1][Y])->coordonneesCase.getPosY() == pSortie->coordonneesCase.getPosY())){		
					return true;
				}

				listeAParcourir.insert(pair<int,Case*>((pCarte->imageCarte[X+1][Y])->distanceEntree + (pCarte->imageCarte[X+1][Y])->heuristique,(pCarte->imageCarte[X+1][Y])));
			}
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
	int X;
	int Y;
	X = (int)floor((float)trace->coordonneesCase.getPosX()/40);
	Y = (int)floor((float)trace->coordonneesCase.getPosY()/40);
	bool jeton;
	cheminIterator = chemin.begin();
	chemin.insert(cheminIterator, trace);
	while ((X != (int)floor((float)coordonnees.getPosX()/40))||(Y != (int)floor((float)coordonnees.getPosY()/40))){
		cheminIterator = chemin.begin();
		jeton = true;
		//nord
		if ((Y>0)&&(jeton == true)){
			if ((pCarte->imageCarte[X][Y - 1]->distanceEntree == (pCarte->imageCarte[X][Y]->distanceEntree - 1))&&(pCarte->imageCarte[X][Y - 1]->caseParcourue == true)){
				trace = pCarte->imageCarte[X][Y - 1];
				jeton = false;
			}
		}
		//puis sud
		//if((Y<sizeof(pCarte->imageCarte))&&(jeton == true)){
		if((Y < pCarte->imageCarteY - 1)&&(jeton == true)) {
			if ((pCarte->imageCarte[X][Y + 1]->distanceEntree == (pCarte->imageCarte[X][Y]->distanceEntree - 1))&&(pCarte->imageCarte[X][Y + 1]->caseParcourue == true)){
				trace = pCarte->imageCarte[X][Y + 1];
				jeton = false;
			}
		}
		//puis ouest
		if ((X>0)&&(jeton == true)){
			if ((pCarte->imageCarte[X - 1][Y]->distanceEntree == (pCarte->imageCarte[X][Y]->distanceEntree - 1))&&(pCarte->imageCarte[X - 1][Y]->caseParcourue == true)){
				trace = pCarte->imageCarte[X - 1][Y];
				jeton = false;
			}
		}
		//et enfin est
		//if ((X<sizeof(pCarte->imageCarte[0]))&&(jeton == true)){
		if((X < pCarte->imageCarteX - 1)&&(jeton == true)) {
			if ((pCarte->imageCarte[X + 1][Y]->distanceEntree == (pCarte->imageCarte[X][Y]->distanceEntree - 1))&&(pCarte->imageCarte[X + 1][Y]->caseParcourue == true)){
				trace = pCarte->imageCarte[X + 1][Y];
				jeton = false;
			}
		}
		chemin.insert(cheminIterator, trace);
		X = (int)floor((float)trace->coordonneesCase.getPosX()/40);
		Y = (int)floor((float)trace->coordonneesCase.getPosY()/40);
	}

	pCarte->nettoyerCarte();
}


