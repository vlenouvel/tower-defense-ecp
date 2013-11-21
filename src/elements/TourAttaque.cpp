/*
 * TourAttaque.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "TourAttaque.h"

TourAttaque::TourAttaque(Coordonnees tCoord) : Tour(tCoord), pCibler(0), attackDamage(0), attackRange(0) {
	amelioration = 0;
	attackDamageBuffed = 0;
	attackRangeBuffed = 0;

	//Recalculer toutes les améliorations ajoutées par les tours support
	ResourceManager *pResourceManager = ResourceManager::getInstance();
	std::vector<Batiment*> listeBat = pResourceManager->getBatiment();
	// On selectionne les tourSupport dans les batiments presents
	// Pour chacune, on lui fait supprimer son amélioration, puis remettre
	for(unsigned int i = 0; i < listeBat.size() ; i++)
	{
		if(listeBat[i]->isTour())
		{
			if(!((Tour*)listeBat[i])->isTourAttaque())
			{
				TourSupport* pTourSupport = (TourSupport*)listeBat[i];
				pTourSupport->recalculerAmelioration();
			}
		}
	}
}

void TourAttaque::agir()
{
	sf::Time timeSinceLastAttack = clockFromLastAttack.getElapsedTime();
	if(timeSinceLastAttack > timeBetweenAttacksBuffed)
	{

		this->trouverCibles();
		if(!this->ciblesPossibles.empty())
		{
			clockFromLastAttack.restart();
			this->attaque(pCibler);
		}
	}
	this->actionSpeciale();
}

void TourAttaque::changerComportementCiblage(ComportementCiblage::Comportement nouveauComportement)
{
	switch(nouveauComportement){
	case ComportementCiblage::Premier:
		comportementChoisi = nouveauComportement;
		pCibler = ComportementCiblage::ciblerPremier;
		break;
	case ComportementCiblage::PlusFaible:
		comportementChoisi = nouveauComportement;
		pCibler = ComportementCiblage::ciblerPlusFaible;
		break;
	case ComportementCiblage::Zone:
		comportementChoisi = nouveauComportement;
		pCibler = ComportementCiblage::ciblerZone;
		break;
	}

}


TourAttaque::~TourAttaque() {
	// TODO Auto-generated destructor stub
}

void TourAttaque::dessiner(sf::RenderWindow &pWindow){
	// TODO
}

void TourAttaque::trouverCibles()
{
	ResourceManager *manager = ResourceManager::getInstance();
	std::vector<Personnage*> listesDeTousLesPersonnages = manager->getPersonnage();
	this->ciblesPossibles.clear();
	if(!listesDeTousLesPersonnages.empty()){
		int posXTour = this->coordonnees.getPosX();
		int posYTour = this->coordonnees.getPosY();
		for(unsigned int i(0); i<listesDeTousLesPersonnages.size(); i++)
		{
			Personnage *perso = listesDeTousLesPersonnages[i];
			int posXPerso = perso->getCoordonnees().getPosX();
			int posYPerso = perso->getCoordonnees().getPosY();
			if((pow((float)(posXPerso - posXTour),2)+pow((float)(posYPerso - posYTour),2)) <= pow((float)attackRangeBuffed,2))
			{
				this->ciblesPossibles.push_back(perso);
			}
		}
	}
}

void TourAttaque::monterNiveau()
{
	attackDamage = (int)(attackDamage*1.5);
	attackRange = (int)(attackRange*1.2);

	// TODO Revoir prix amelioration
	ResourceManager* manager = ResourceManager::getInstance();

	manager->getRessources()->perdreArgent((int)(prix*0.75));
	prix += (int)(prix*0.75);
	niveau++;
}

bool TourAttaque::isTourAttaque()
{
	return true;
}

int TourAttaque::getDommages()
{
	return attackDamageBuffed;
}

void TourAttaque::addAmelioration(int amelio)
{
	amelioration+=amelio;
	calculerValeursAmeliorees();
}

void TourAttaque::removeAmelioration(int amelio)
{
	amelioration-=amelio;
	if(amelioration < 0)
		amelioration = 0;
	calculerValeursAmeliorees();
}

void TourAttaque::calculerValeursAmeliorees()
{
	attackDamageBuffed = (int)(attackDamage*(1+amelioration/10));
	attackRangeBuffed = (int)(attackRange*(1+amelioration/10));
	timeBetweenAttacksBuffed = sf::milliseconds((sf::Int32)timeBetweenAttacks.asMilliseconds()/(1+0.75*(1-exp((float)-amelioration/10))));
}

ComportementCiblage::Comportement TourAttaque::getComportement()
{
	return comportementChoisi;
}
