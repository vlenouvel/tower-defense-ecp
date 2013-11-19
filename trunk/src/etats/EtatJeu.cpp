/*
 * EtatJeu.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "EtatJeu.h"

using namespace std;


EtatJeu::EtatJeu(App *tApp) : Etat(tApp), pApp(tApp) {
	ResourceManager* manager = ResourceManager::getInstance();

	//manager->addEtatJeu(this);

	// Creation de la carte
	carte = new Carte();
	pTableauDeBord = new TableauDeBord();
	manager->addCarte(carte);

	pRessources = new Ressources();
	manager->addRessources(pRessources);

	batimentChoisi = BASIQUE;

	//Creation du generateur de vague
	GenerateurVague* pGenerateur = new GenerateurVague();
	manager->addGenerateurVague(pGenerateur);

	Coordonnees coordonneesPersoFictif(1,1);
	manager->pPersoFictif = new Personnage(1,0,1,coordonneesPersoFictif);
	arriveCase.setSize(sf::Vector2f(40, 40));
	arriveCase.setPosition(680,560);
	arriveCase.setFillColor(sf::Color::Red);

	tempsDisparitionErreur = sf::seconds((float)1);


	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();

	erreur = "";
	font = pResourcesLoader->policeTableauDeBord;
	texteErreur.setFont(font);
	texteErreur.setCharacterSize(16);
	texteErreur.setColor(sf::Color::Red);
	texteErreur.setStyle(sf::Text::Bold);
	texteErreur.setPosition(100,250);

}

void EtatJeu::setErreur(string erreurMsg) {

	erreur = erreurMsg;
	tempsErreur = pApp->horloge.getElapsedTime();
}

void EtatJeu::handleEvent(sf::Event event)
{
	ResourceManager* manager = ResourceManager::getInstance();
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			if ((event.mouseButton.x>760)&&(event.mouseButton.x<795)&&(event.mouseButton.y<335)&&(event.mouseButton.y>300)){
				batimentChoisi = BASIQUE;
				manager->setTourSelectionnee(0);
			}
			else if ((event.mouseButton.x>710)&&(event.mouseButton.x<745)&&(event.mouseButton.y<335)&&(event.mouseButton.y>300)){
				batimentChoisi = CANON;
				manager->setTourSelectionnee(0);
			}
			else if((event.mouseButton.x>680)&&(event.mouseButton.y>560)) {
				setErreur("Vous ne pouvez pas construire sur la sortie !");
			}
			else if((event.mouseButton.x<40)&&(event.mouseButton.y<40)) {
				setErreur("Vous ne pouvez pas construire sur l'entree !");
			}
			else if ((event.mouseButton.x>710)&&(event.mouseButton.x<740)&&(event.mouseButton.y>400)&&(event.mouseButton.y<430)&&(manager->getTourSelectionnee()!=0))
			{
				if (manager->getTourSelectionnee()->verifierAmelioration())
				{
					manager->getTourSelectionnee()->monterNiveau();
				}
				else
				{
					setErreur("Vous n'avez pas assez d'argent pour ameliorer cette tour.");
				}
			}
			else if ((event.mouseButton.x>750)&&(event.mouseButton.x<780)&&(event.mouseButton.y>400)&&(event.mouseButton.y<430)&&(manager->getTourSelectionnee()!=0))
			{
				int indiceX = (manager->getTourSelectionnee()->getCoordonnees().getPosX()-20)/40;
				int indiceY = (manager->getTourSelectionnee()->getCoordonnees().getPosY()-20)/40;
				manager->getTourSelectionnee()->vendreTour();
				manager->getCarte()->imageCarte[indiceX][indiceY]->caseOccupee = false;
			}
			else if ((event.mouseButton.x<700)){
				manager->setTourSelectionnee(0);
				bool autorisation = true;
				// Indices de la case cliquee.
				int indiceX = (int)floor((float)event.mouseButton.x/40);
				int indiceY = (int)floor((float)event.mouseButton.y/40);
				bool caseEstOccupee = (manager->getCarte())->imageCarte[indiceX][indiceY]->caseOccupee;
				if(caseEstOccupee) {
					vector<Tour*> tourConteneur = manager->getTour();
					for (unsigned int i=0; i<tourConteneur.size(); i++)
					{
						int coordXTour = tourConteneur[i]->getCoordonnees().getPosX();
						int coordYTour = tourConteneur[i]->getCoordonnees().getPosY();
						if ((coordXTour == (40*indiceX + 20))&&(coordYTour == (40*indiceY + 20)))
						{
							manager->setTourSelectionnee(tourConteneur[i]);
						}
					}

				} else {
					(manager->getCarte())->imageCarte[indiceX][indiceY]->caseOccupee = true;
					if (!manager->getPersonnage().empty()){
						for (unsigned int i=0; i< manager->getPersonnage().size();i++){
							autorisation = ((manager->getPersonnage())[i])->trouverChemin(manager->getCarte());
							manager->getCarte()->nettoyerCarte();
							if (autorisation == false){
								break;
							}
						}
					}
					autorisation = manager->pPersoFictif->trouverChemin(manager->getCarte());
					manager->getCarte()->nettoyerCarte();
					if(autorisation == false) {
						setErreur("Vous ne pouvez pas bloquer le passage des ennemis !");
						(manager->getCarte())->imageCarte[indiceX][indiceY]->caseOccupee = false;
					}
					else if ((autorisation == true)&&(!caseEstOccupee)){
						Coordonnees coordonneesTour(40*indiceX+20,40*indiceY+20);
						construireTour(batimentChoisi, coordonneesTour);
					}
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


	if(manager->getRessources()->getVie() < 1) {

		EtatMort* etatmort = new EtatMort(pApp);
		pApp->changerEtat(etatmort);
	}

}

void EtatJeu::dessiner(sf::RenderWindow &pWindow){

	ResourceManager* manager = ResourceManager::getInstance();

	carte->dessiner(pWindow);
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
	vector<ElementGraphique*> objetAnnexeConteneur = manager->getObjetAnnexe();
	if (!objetAnnexeConteneur.empty()){
		for(unsigned int i=0;i<objetAnnexeConteneur.size();++i){
			objetAnnexeConteneur[i]->dessiner(pWindow);
		}
	}

	texteErreur.setString(erreur);
	if(pApp->horloge.getElapsedTime() - tempsErreur < tempsDisparitionErreur) {
		pWindow.draw(texteErreur);
	}
}

EtatJeu::~EtatJeu() {
	// TODO Auto-generated destructor stub
}


void EtatJeu::construireTour(typeBatiment type, Coordonnees coord)
{
	ResourceManager *pResourceManager = ResourceManager::getInstance();
	Tour *pTour = 0;
	int indiceX = (int)floor((float)coord.getPosX()/40);
	int indiceY = (int)floor((float)coord.getPosY()/40);
	switch(batimentChoisi){
		case BASIQUE:
			pTour = new TourAttaqueBasique(coord);
			break;
		case CANON:
			pTour = new CanonLourd(coord);
			break;
		case EXPLOSIF:
			break;
		case FROST:
			break;
		case MUR:
			break;
		}
	if(pTour->verifierAchat())
	{
		(pResourceManager->getCarte())->imageCarte[indiceX][indiceY]->caseOccupee = true;
		pResourceManager->addTour(pTour);
		pResourceManager->getRessources()->perdreArgent(pTour->getPrix());

		// On recalcule les chemins pour les ennemis, car on a construit un batiment.
		if (!(pResourceManager->getPersonnage()).empty()){
			for (unsigned int i=0; i< (pResourceManager->getPersonnage()).size();i++){
				pResourceManager->getPersonnage()[i]->trouverChemin(pResourceManager->getCarte());
				pResourceManager->getPersonnage()[i]->ecrireChemin(pResourceManager->getCarte());
			}
		}
	} else {
		delete pTour;
		(pResourceManager->getCarte())->imageCarte[indiceX][indiceY]->caseOccupee = false;
		setErreur("Pas assez d'argent !");
	}
}
