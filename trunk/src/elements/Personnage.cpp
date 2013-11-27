/*
 * Personnage.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "Personnage.h"

Personnage::Personnage(int tVie, int tVitesse, int tArmure, int tGain, Coordonnees tCoord) : 
	coordonnees(tCoord), vie(tVie), vitesse(tVitesse), armure(tArmure), gain(tGain)
{

	// on traite les textures du personnage et de sa barre de vie
	spritePersonnage.setPosition(tCoord.posX,tCoord.posY);
	barreDeVieVerte.setFillColor(sf::Color::Green);
	barreDeVieVerte.setSize(sf::Vector2f(sf::Vector2f(spritePersonnage.getGlobalBounds().width, 5)));
	barreDeVieVerte.setPosition(tCoord.posX, tCoord.posY - 8);
	barreDeVieRouge.setFillColor(sf::Color::Red);
	barreDeVieRouge.setSize(sf::Vector2f(0,5));
	barreDeVieRouge.setPosition(tCoord.posX, tCoord.posY - 8);

	pourcentageVitesseMalus = 0;
	vieInitial = vie;
}

void Personnage::agir()
{
	this->avancer();
}

void Personnage::avancer()
{
	if(!chemin.empty()){
		int imageVitesse = (int)(vitesse*(100 - pourcentageVitesseMalus)/100+0.5);
		if (imageVitesse < 2)
			imageVitesse = 2;
		int abscisseCible,ordonneeCible,abscissePerso,ordonneePerso,distanceCiblePerso;
		while (imageVitesse > 0){
			abscisseCible = chemin[0]->coordonneesCase.getPosX();
			ordonneeCible = chemin[0]->coordonneesCase.getPosY();
			abscissePerso = coordonnees.getPosX();
			ordonneePerso = coordonnees.getPosY();
			distanceCiblePerso = (int)(sqrt((pow((float)abscisseCible - abscissePerso,2) + pow((float)ordonneeCible - ordonneePerso,2)))+0.5);
			if (distanceCiblePerso > imageVitesse){
				coordonnees.setPosX(abscissePerso+(int)((float)(abscisseCible - abscissePerso)*imageVitesse/distanceCiblePerso+0.5));
				coordonnees.setPosY(ordonneePerso+(int)((float)(ordonneeCible - ordonneePerso)*imageVitesse/distanceCiblePerso+0.5));
				imageVitesse = 0;
			}

			else {
				imageVitesse -= distanceCiblePerso;
				// TODO Checker bugfix ici !!
				if (!chemin.empty())
					chemin.erase(chemin.begin());
					break;
			}
		}
		spritePersonnage.setPosition(coordonnees.posX,coordonnees.posY);
		barreDeVieRouge.setPosition(coordonnees.posX,coordonnees.posY-8);
		barreDeVieVerte.setPosition(coordonnees.posX,coordonnees.posY-8);
	}
	else {
		arriver();
	}
	if (pourcentageVitesseMalus > 0)
		pourcentageVitesseMalus--;
}

void Personnage::perdrePV(int degat)
{
	if(degat > armure){
		vie -= (degat - armure);
		if(vie <= 0)
			this->mourir();
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
			pProjo->setCible(0);
		}
	}

	manager->getRessources()->gagnerArgent(gain);
	manager->getRessources()->augmenterScore(gain);
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
			// On met a 0 cible du projectile, ce qui le conduit a etre delete dans son agir.
			pProjo->setCible(0);
		}
	}
}

Personnage::~Personnage() {
	// TODO Auto-generated destructor stub.
}

void Personnage::dessiner(sf::RenderWindow &pWindow)
{
	barreDeVieRouge.setSize(sf::Vector2f(spritePersonnage.getGlobalBounds().width*(vieInitial - vie)/vieInitial,5));
	pWindow.draw(spritePersonnage);
	pWindow.draw(barreDeVieVerte);
	pWindow.draw(barreDeVieRouge);
}

int Personnage::getVie()
{
	return this->vie;
}

Coordonnees Personnage::getCoordonnees()
{
	return this->coordonnees;
}

/*  
	Cette fonction est la premiere des deux fonctions de l'algorithme de path-finding.
	Elle prend en entree un pointeur vers la carte ce qui nous permet de savoir quel est l'etat
	de la carte et d'obtenir toutes les informations necessaires pour savoir si oui ou non, le 
	personnage a un chemin possible vers la sortie. Si oui, vrai est retourne. Si non, faux est retourne.
	L'algorithme implemente est A* 
*/
bool Personnage::trouverChemin(Carte * pCarte){

	//on initialise la liste triee qui va contenir la suite de case a analyser avec la case d'entree
	multimap<int,Case*> listeAParcourir;
	multimap<int,Case*>::iterator myIterator;
	
	//attention, le terme "entree" designe ici la position du personnage a l'endroit ou l'algorithme est invoque
	Case * pEntree = pCarte->imageCarte[(int)floor((float)coordonnees.getPosX()/40)][(int)floor((float)coordonnees.getPosY()/40)];
	Case * pSortie = pCarte->pCaseSortie;
	
	//on traite d'abord la case d'entree
	listeAParcourir.insert(pair<int,Case*>(pEntree->heuristique,pEntree));
	pCarte->imageCarte[(int)floor((float)coordonnees.getPosX()/40)][(int)floor((float)coordonnees.getPosY()/40)]->distanceEntree = 0;

	//boucle principale de l'algo. L'algo s'arrete dans deux cas : soit on atteint la sortie, soit on ne l'atteint pas et dans ce cas, 
	//la liste a parcourir est vide
	int X,Y;
	while (!listeAParcourir.empty()){
		myIterator = listeAParcourir.begin();
		X = (int)floor((float)(myIterator->second)->coordonneesCase.getPosX()/40);
		Y = (int)floor((float)(myIterator->second)->coordonneesCase.getPosY()/40);
		pCarte->imageCarte[X][Y]->caseParcourue = true;

		//on etudie le nord, le sud, l'ouest et l'est par rapport a X,Y
		//nord
		if (Y>0){
			if (((pCarte->imageCarte[X][Y-1])->caseParcourue == false) && (((pCarte->imageCarte[X][Y-1])->caseOccupee == false)||isVolant())){
				(pCarte->imageCarte[X][Y-1])->distanceEntree = (pCarte->imageCarte[X][Y])->distanceEntree + 1;
				(pCarte->imageCarte[X][Y-1])->caseParcourue = true;
				if (((pCarte->imageCarte[X][Y-1])->coordonneesCase.getPosX() == pSortie->coordonneesCase.getPosX())&&((pCarte->imageCarte[X][Y-1])->coordonneesCase.getPosY() == pSortie->coordonneesCase.getPosY())){
					return true;
				}
				listeAParcourir.insert(pair<int,Case*>((pCarte->imageCarte[X][Y-1])->distanceEntree + (pCarte->imageCarte[X][Y-1])->heuristique,pCarte->imageCarte[X][Y-1]));
			}
		}
		//sud
		if(Y < pCarte->imageCarteY -1) {
			if (((pCarte->imageCarte[X][Y+1])->caseParcourue == false) && (((pCarte->imageCarte[X][Y+1])->caseOccupee == false)|| isVolant())){
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
			if (((pCarte->imageCarte[X-1][Y])->caseParcourue == false) && (((pCarte->imageCarte[X-1][Y])->caseOccupee == false)||isVolant())){
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
			if (((pCarte->imageCarte[X+1][Y])->caseParcourue == false) && (((pCarte->imageCarte[X+1][Y])->caseOccupee == false)||isVolant())){
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
/*
	Cette seconde fonction calcule, sous reserve que la premiere fonction ait retourne vrai, le chemin le plus court
	a prendre vers la sortie. Ce chemin est une suite de cases qu'emprunte ensuite le personnage qui se deplace alors
	de case en case. Il faut que la fonction precedente ait ete appelee juste avant celle-ci
*/
void Personnage::ecrireChemin(Carte * pCarte){
	chemin.clear();
	Case * trace;
	trace = pCarte->pCaseSortie;
	int X;
	int Y;
	X = (int)floor((float)trace->coordonneesCase.getPosX()/40);
	Y = (int)floor((float)trace->coordonneesCase.getPosY()/40);
	bool jeton;
	cheminIterator = chemin.begin();
	chemin.insert(cheminIterator, trace);
	// boucle principale
	while ((X != (int)floor((float)coordonnees.getPosX()/40))||(Y != (int)floor((float)coordonnees.getPosY()/40))){
		cheminIterator = chemin.begin();
		jeton = true;
		int ordre = rand() % 4;
		while (jeton){
			//nord
			if ((Y>0)&&(jeton == true)&&(ordre%4 == 0)){
				if ((pCarte->imageCarte[X][Y - 1]->distanceEntree == (pCarte->imageCarte[X][Y]->distanceEntree - 1))&&(pCarte->imageCarte[X][Y - 1]->caseParcourue == true)){
					trace = pCarte->imageCarte[X][Y - 1];
					jeton = false;
				}
			}
			//puis sud
			if((Y < pCarte->imageCarteY - 1)&&(jeton == true)&&(ordre%4 == 1)) {
				if ((pCarte->imageCarte[X][Y + 1]->distanceEntree == (pCarte->imageCarte[X][Y]->distanceEntree - 1))&&(pCarte->imageCarte[X][Y + 1]->caseParcourue == true)){
					trace = pCarte->imageCarte[X][Y + 1];
					jeton = false;
				}
			}
			//puis ouest
			if ((X>0)&&(jeton == true)&&(ordre%4 == 2)){
				if ((pCarte->imageCarte[X - 1][Y]->distanceEntree == (pCarte->imageCarte[X][Y]->distanceEntree - 1))&&(pCarte->imageCarte[X - 1][Y]->caseParcourue == true)){
					trace = pCarte->imageCarte[X - 1][Y];
					jeton = false;
				}
			}
			//et enfin est
			if((X < pCarte->imageCarteX - 1)&&(jeton == true)&&(ordre%4 == 3)) {
				if ((pCarte->imageCarte[X + 1][Y]->distanceEntree == (pCarte->imageCarte[X][Y]->distanceEntree - 1))&&(pCarte->imageCarte[X + 1][Y]->caseParcourue == true)){
					trace = pCarte->imageCarte[X + 1][Y];
					jeton = false;
				}
			}
			ordre++;
		}
		chemin.insert(cheminIterator, trace);
		X = (int)floor((float)trace->coordonneesCase.getPosX()/40);
		Y = (int)floor((float)trace->coordonneesCase.getPosY()/40);
	}
	chemin.erase(chemin.begin());
	pCarte->nettoyerCarte();
}

int Personnage::getPoucentageVitesseMalus()
{
	return pourcentageVitesseMalus;
}

void Personnage::setPourcentageVitesseMalus(int malus)
{
	pourcentageVitesseMalus = malus;
}

bool Personnage::isVolant()
{
	return false;
}
