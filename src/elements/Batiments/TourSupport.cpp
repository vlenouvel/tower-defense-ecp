/*
 * TourSupport.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "TourSupport.h"

TourSupport::TourSupport(Coordonnees tCoord) : Tour(tCoord) {
	ConfigManager *pConfigManager = ConfigManager::getInstance();
	prix = pConfigManager->mapTourSupport["prix"];
	ResourcesLoader *pResourcesLoader = ResourcesLoader::getInstance();
	spriteElement.setTexture(pResourcesLoader->textureTourSupport);
	spriteElement.setScale(0.5,0.5);
	spriteElement.setPosition((float)(tCoord.getPosX()/40)*40,floor((float)(tCoord.getPosY()/40))*40);
	ajouterAmelioration(niveau);
}

void TourSupport::agir()
{

}

void TourSupport::handleEvent(sf::Event event)
{

}

void TourSupport::monterNiveau()
{
	Tour::monterNiveau();
	ajouterAmelioration(1);
}

TourSupport::~TourSupport() {
}

void TourSupport::dessiner(sf::RenderWindow &pWindow){
	pWindow.draw(spriteElement);
}

bool TourSupport::isTourAttaque()
{
	return false;
}

void TourSupport::recalculerAmelioration()
{
	enleverAmelioration();
	ajouterAmelioration(niveau);
}

void TourSupport::ajouterAmelioration(int valeur)
{
	ResourceManager *resourceManager = ResourceManager::getInstance();
	std::vector<Batiment*> listeBat = resourceManager->getBatiment();
	// On selectionne les tourAttaque dans les batiments presents
	// Puis pour chaque on regarde si ses coordonnees sur le cercle de 40 de rayon
	// Si oui, elle est adjacente � la tour support, on la buff donc
	for(unsigned int i = 0; i < listeBat.size() ; i++)
	{
		if(listeBat[i]->isTour())
		{
			if(((Tour*)listeBat[i])->isTourAttaque())
			{
				TourAttaque* pTourAttaque = (TourAttaque*)listeBat[i];
				int distX = abs((float)(coordonnees.getPosX() - pTourAttaque->getCoordonnees().getPosX()));
				int distY = abs((float)(coordonnees.getPosY() - pTourAttaque->getCoordonnees().getPosY()));
				if((distX == 40 && distY != 40)||(distX != 40 && distY == 40))
				{
					pTourAttaque->addAmelioration(valeur);
				}
			}
		}
	}
}

void TourSupport::enleverAmelioration()
{
	ResourceManager *resourceManager = ResourceManager::getInstance();
	std::vector<Batiment*> listeBat = resourceManager->getBatiment();
	// On selectionne les tourAttaque dans les batiments presents
	// Puis pour chaque on regarde si ses coordonnees sur le cercle de 40 de rayon
	// Si oui, elle est adjacente � la tour support, on la buff donc
	for(unsigned int i = 0; i < listeBat.size() ; i++)
	{
		if(listeBat[i]->isTour())
		{
			if(((Tour*)listeBat[i])->isTourAttaque())
			{
				TourAttaque* pTourAttaque = (TourAttaque*)listeBat[i];
				int distX = abs((float)(coordonnees.getPosX() - pTourAttaque->getCoordonnees().getPosX()));
				int distY = abs((float)(coordonnees.getPosY() - pTourAttaque->getCoordonnees().getPosY()));
				if((distX == 40 && distY != 40)||(distX != 40 && distY == 40))
				{
					pTourAttaque->removeAmelioration(niveau);
				}
			}
		}
	}
}

void TourSupport::vendreBatiment()
{
	enleverAmelioration();
	Batiment::vendreBatiment();
}
