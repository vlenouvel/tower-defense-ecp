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

	// Creation de la carte
	carte = new Carte();
	pTableauDeBord = new TableauDeBord();
	manager->addCarte(carte);

	pRessources = new Ressources();
	manager->addRessources(pRessources);

	batimentChoisi = TableauDeBord::AUCUN;

	//Creation du generateur de vague
	GenerateurVague* pGenerateur = new GenerateurVague();
	manager->addGenerateurVague(pGenerateur);

	Coordonnees coordonneesPersoFictif(1,1);
	manager->addPersoFictif(new Personnage(1,0,1,0,coordonneesPersoFictif));
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
				batimentChoisi = TableauDeBord::BASIQUE;
				manager->setBatimentSelectionne(0);
			}
			else if ((event.mouseButton.x>710)&&(event.mouseButton.x<745)&&(event.mouseButton.y<335)&&(event.mouseButton.y>300)){
				batimentChoisi = TableauDeBord::CANON;
				manager->setBatimentSelectionne(0);
			}
			else if ((event.mouseButton.x>705)&&(event.mouseButton.x<745)&&(event.mouseButton.y<290)&&(event.mouseButton.y>250)){
				batimentChoisi = TableauDeBord::FROST;
				manager->setBatimentSelectionne(0);
			}
			else if((event.mouseButton.x>760)&&(event.mouseButton.x<795)&&(event.mouseButton.y<290)&&(event.mouseButton.y>250))
			{
				batimentChoisi = TableauDeBord::MUR;
				manager->setBatimentSelectionne(0);
			}
			else if((event.mouseButton.x>680)&&(event.mouseButton.y>560)) {
				setErreur("Vous ne pouvez pas construire sur la sortie !");
			}
			else if((event.mouseButton.x<40)&&(event.mouseButton.y<40)) {
				setErreur("Vous ne pouvez pas construire sur l'entree !");
			}
			else if ((event.mouseButton.x>710)&&(event.mouseButton.x<740)&&(event.mouseButton.y>400)&&(event.mouseButton.y<430)&&(manager->getBatimentSelectionne()!=0))
			{
				if(manager->getBatimentSelectionne()->isTour()){
					if (((Tour*)manager->getBatimentSelectionne())->verifierAmelioration())
					{
						((Tour*)manager->getBatimentSelectionne())->monterNiveau();
					}
					else
					{
						setErreur("Vous n'avez pas assez d'argent pour ameliorer cette tour.");
					}
				}
			}
			else if ((event.mouseButton.x>750)&&(event.mouseButton.x<780)&&(event.mouseButton.y>400)&&(event.mouseButton.y<430)&&(manager->getBatimentSelectionne()!=0))
			{
				int indiceX = (manager->getBatimentSelectionne()->getCoordonnees().getPosX()-20)/40;
				int indiceY = (manager->getBatimentSelectionne()->getCoordonnees().getPosY()-20)/40;
				manager->getBatimentSelectionne()->vendreBatiment();
				manager->getCarte()->imageCarte[indiceX][indiceY]->caseOccupee = false;
			}
			else if ((event.mouseButton.x>710)&&(event.mouseButton.x<780)&&(event.mouseButton.y>470)&&(event.mouseButton.y<480)&&(manager->getBatimentSelectionne()!=0))
			{
				if(manager->getBatimentSelectionne()->isTour())
				{
					if(((Tour*)manager->getBatimentSelectionne())->isTourAttaque())
					{
						((TourAttaque*)manager->getBatimentSelectionne())->changerComportementCiblage(ComportementCiblage::Premier);
					}
				}
			}
			else if ((event.mouseButton.x>710)&&(event.mouseButton.x<780)&&(event.mouseButton.y>480)&&(event.mouseButton.y<490)&&(manager->getBatimentSelectionne()!=0))
			{
				if(manager->getBatimentSelectionne()->isTour())
				{
					if(((Tour*)manager->getBatimentSelectionne())->isTourAttaque())
					{
						((TourAttaque*)manager->getBatimentSelectionne())->changerComportementCiblage(ComportementCiblage::PlusFaible);
					}
				}
			}
			else if ((event.mouseButton.x<700)){
				manager->setBatimentSelectionne(0);
				bool autorisation = true;
				// Indices de la case cliquee.
				int indiceX = (int)floor((float)event.mouseButton.x/40);
				int indiceY = (int)floor((float)event.mouseButton.y/40);
				bool caseEstOccupee = (manager->getCarte())->imageCarte[indiceX][indiceY]->caseOccupee;
				if(caseEstOccupee) {
					batimentChoisi = TableauDeBord::AUCUN;
					vector<Batiment*> batimentConteneur = manager->getBatiment();
					for (unsigned int i=0; i<batimentConteneur.size(); i++)
					{
						int coordXTour = batimentConteneur[i]->getCoordonnees().getPosX();
						int coordYTour = batimentConteneur[i]->getCoordonnees().getPosY();
						if ((coordXTour == (40*indiceX + 20))&&(coordYTour == (40*indiceY + 20)))
						{
							manager->setBatimentSelectionne(batimentConteneur[i]);
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
					autorisation = manager->getPersoFictif()->trouverChemin(manager->getCarte());
					manager->getCarte()->nettoyerCarte();
					if(autorisation == false) {
						setErreur("Vous ne pouvez pas bloquer le passage des ennemis !");
						(manager->getCarte())->imageCarte[indiceX][indiceY]->caseOccupee = false;
					}
					else if ((autorisation == true)&&(!caseEstOccupee)&&(batimentChoisi!=TableauDeBord::AUCUN)){
						Coordonnees coordonneesTour(40*indiceX+20,40*indiceY+20);
						construireBatiment(batimentChoisi, coordonneesTour);
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


	vector<Batiment*> batimentConteneur = manager->getBatiment();
	if (!batimentConteneur.empty()){
		for(unsigned int i=0;i<batimentConteneur.size();i++){
			batimentConteneur[i]->agir();
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



	pWindow.draw(arriveCase);

	vector<Batiment*> batimentConteneur = manager->getBatiment();

	if (!batimentConteneur.empty()){
		for(unsigned int i=0;i<batimentConteneur.size();i++){
			batimentConteneur[i]->dessiner(pWindow);
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

	pTableauDeBord->dessiner(pWindow);

	// Met en couleur le batiment selectionnee dans le menu
	pTableauDeBord->setSelectionBat(batimentChoisi);

	texteErreur.setString(erreur);
	if(pApp->horloge.getElapsedTime() - tempsErreur < tempsDisparitionErreur) {
		pWindow.draw(texteErreur);
	}
}

EtatJeu::~EtatJeu() {
	// TODO Auto-generated destructor stub
}


void EtatJeu::construireBatiment(TableauDeBord::typeBatiment type, Coordonnees coord)
{
	ResourceManager *pResourceManager = ResourceManager::getInstance();
	Batiment *pBatiment = 0;
	int indiceX = (int)floor((float)coord.getPosX()/40);
	int indiceY = (int)floor((float)coord.getPosY()/40);
	switch(batimentChoisi){
		case TableauDeBord::AUCUN:
			(pResourceManager->getCarte())->imageCarte[indiceX][indiceY]->caseOccupee = false;
			break;
		case TableauDeBord::BASIQUE:
			pBatiment = new TourAttaqueBasique(coord);
			break;
		case TableauDeBord::CANON:
			pBatiment = new CanonLourd(coord);
			break;
		case TableauDeBord::EXPLOSIF:
			break;
		case TableauDeBord::FROST:
			pBatiment = new TourDeGlace(coord);
			break;
		case TableauDeBord::MUR:
			pBatiment = new Mur(coord);
			break;
		}
	if(pBatiment->verifierAchat())
	{
		(pResourceManager->getCarte())->imageCarte[indiceX][indiceY]->caseOccupee = true;
		pResourceManager->addBatiment(pBatiment);
		pResourceManager->getRessources()->perdreArgent(pBatiment->getPrix());

		// On recalcule les chemins pour les ennemis, car on a construit un batiment.
		if (!(pResourceManager->getPersonnage()).empty()){
			for (unsigned int i=0; i< (pResourceManager->getPersonnage()).size();i++){
				pResourceManager->getPersonnage()[i]->trouverChemin(pResourceManager->getCarte());
				pResourceManager->getPersonnage()[i]->ecrireChemin(pResourceManager->getCarte());
			}
		}
	} else {
		delete pBatiment;
		(pResourceManager->getCarte())->imageCarte[indiceX][indiceY]->caseOccupee = false;
		setErreur("Pas assez d'argent !");
	}
}
