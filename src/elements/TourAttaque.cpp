/*
 * TourAttaque.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "TourAttaque.h"

TourAttaque::TourAttaque(int tPrix, Coordonnees tCoord) : Tour(tPrix, tCoord), pCibler(0), attackDamage(0), attackRange(0) {
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
