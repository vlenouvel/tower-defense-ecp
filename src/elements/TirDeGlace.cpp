/*
 * TirDeGlace.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "TirDeGlace.h"
#define PI 3.14159265

TirDeGlace::TirDeGlace(Coordonnees tCoord, Personnage* tCible, int tDommages, int tRayonExplosion) :
	Projectile(tCoord, tCible, tDommages), rayonExplosion(tRayonExplosion) {
	vitesse = 8;
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spriteProjectile.setTexture(pResourcesLoader->textureTirDeGlace);
	spriteProjectile.setScale(0.5,0.3);
	spriteProjectile.setPosition(tCoord.posX,tCoord.posY);
	rotation = 0;
}

void TirDeGlace::avancer()
{
	int xproj = this->coordonnees.getPosX();
	int yproj = this->coordonnees.getPosY();
	int xperso = this->cible->getCoordonnees().getPosX() + 12;
	int yperso = this->cible->getCoordonnees().getPosY() + 20;
	double distance = sqrt(pow((float)(xperso-xproj),2)+pow((float)(yperso-yproj),2));
	double alpha = this->vitesse/distance;
	if (alpha > 1)
	{
		// Si alpha > 1, cela veut dire que le projectile s'apprete a parcourir une
		// distance plus grande que celle qui le separe de la cible
		alpha = 1;
	}
	int newxproj = (int)floor(alpha*(xperso-xproj)) + xproj;
	int newyproj = (int)floor(alpha*(yperso-yproj)) + yproj;
	distance = sqrt(pow((float)(xperso-newxproj),2)+pow((float)(yperso-newyproj),2));
	this->coordonnees.setPosX(newxproj);
	this->coordonnees.setPosY(newyproj);
	if((abs(xperso-newxproj)+abs(yperso-newyproj)) < 5){
		this->toucherEnnemi();
	}
	else{
		if ((newxproj - xperso) == 0)
			newxproj++;
		rotation = (float)atan((float)(newyproj - yperso)/(newxproj - xperso))*180/PI;
		if ((newxproj - xperso)>0)
			rotation +=180;
		spriteProjectile.setRotation(rotation+180);
		spriteProjectile.setPosition(newxproj, newyproj);
	}
}

void TirDeGlace::toucherEnnemi()
{
	ResourceManager *manager = ResourceManager::getInstance();
	std::vector<Personnage*> listePerso = manager->getPersonnage();
	int posXTour = this->coordonnees.getPosX();
	int posYTour = this->coordonnees.getPosY();
	for(unsigned int i(0); i<listePerso.size(); i++)
	{
		Personnage *perso = listePerso[i];
		int posXPerso = perso->getCoordonnees().getPosX();
		int posYPerso = perso->getCoordonnees().getPosY();

		if((pow((float)(posXPerso - posXTour),2)+pow((float)(posYPerso - posYTour),2)) <= pow((float)(this->rayonExplosion),2))
		{
			perso->pourcentageVitesseMalus = 60;
			perso->perdrePV(this->dommages);
		}
	}
	manager->removeProjectile(this);
	delete this;
}

void TirDeGlace::dessiner(sf::RenderWindow & rWindow){
	rWindow.draw(spriteProjectile);
}


TirDeGlace::~TirDeGlace() {
	// TODO Auto-generated destructor stub
}
