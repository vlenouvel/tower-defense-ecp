/*
 * TourAttaque.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "TourAttaque.h"

TourAttaque::TourAttaque(Coordonnees tCoord) : Tour(tCoord), pCibler(0), attackDamage(0), attackRange(0) {
}

void TourAttaque::agir()
{
	sf::Time timeSinceLastAttack = clockFromLastAttack.getElapsedTime();
	if(timeSinceLastAttack > timeBetweenAttacks)
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

void TourAttaque::changerComportementCiblage(Personnage* (*fonctionCiblage)(std::vector<Personnage*> ciblesPossibles))
{
	pCibler = fonctionCiblage;
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
			if((pow((float)(posXPerso - posXTour),2)+pow((float)(posYPerso - posYTour),2)) <= pow((float)(this->attackRange),2))
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
	return attackDamage;
}
