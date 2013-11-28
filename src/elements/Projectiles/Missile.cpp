/*
 * Missile.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "Missile.h"
#define PI 3.14159265

Missile::Missile(Coordonnees tCoord, Personnage* tCible, int tDommages, int tRayonExplosion) :
	Projectile(tCoord, tCible, tDommages), rayonExplosion(tRayonExplosion) {
	vitesse = 1;
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spriteElement.setTexture(pResourcesLoader->textureMissile);
	spriteElement.setScale(0.04,0.08);
	spriteElement.setPosition(tCoord.getPosX(),tCoord.getPosY());
	spriteTrainee.setTexture(pResourcesLoader->textureTraineeMissile1);
	spriteTrainee.setScale(0.4,0.4);
	momentDuCycle = 0;
	rotation = 0;
}

void Missile::avancer()
{
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	if (momentDuCycle > 19){
		vitesse++;
		switch(momentDuCycle%4){
		case 0:
			spriteTrainee.setTexture(pResourcesLoader->textureTraineeMissile6);
			break;
		case 1:
			spriteTrainee.setTexture(pResourcesLoader->textureTraineeMissile7);
			break;
		case 2:
			spriteTrainee.setTexture(pResourcesLoader->textureTraineeMissile8);
			break;
		case 3:
			spriteTrainee.setTexture(pResourcesLoader->textureTraineeMissile9);
			break;
		}
	}
	else{
		switch(momentDuCycle){
		case 4:
			spriteTrainee.setTexture(pResourcesLoader->textureTraineeMissile2);
			vitesse = 2;
			break;
		case 8:
			spriteTrainee.setTexture(pResourcesLoader->textureTraineeMissile3);
			vitesse = 3;
			break;
		case 12:
			spriteTrainee.setTexture(pResourcesLoader->textureTraineeMissile4);
			vitesse = 4;
			break;
		case 16:
			spriteTrainee.setTexture(pResourcesLoader->textureTraineeMissile5);
			vitesse = 5;
			break;
		default:
			vitesse = 6;
			break;
		}
	}
	momentDuCycle++;
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
		spriteElement.setRotation(rotation+180);
		spriteElement.setPosition(newxproj, newyproj);
		spriteTrainee.setRotation(rotation+180);
		spriteTrainee.setPosition(newxproj+26*(newxproj-xperso)/distance,newyproj+26*(newyproj-yperso)/distance);
	}
}

void Missile::toucherEnnemi()
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
			perso->perdrePV(this->dommages);
		}
	}
	Coordonnees coordonneesImpact(this->coordonnees.getPosX(),this->coordonnees.getPosY());
	ExplosionMissile * explosionMissile = new ExplosionMissile(coordonneesImpact);
	manager->addObjetAnnexe(explosionMissile);
	manager->removeProjectile(this);
	delete this;
}

void Missile::dessiner(sf::RenderWindow & rWindow){
	rWindow.draw(spriteElement);
	rWindow.draw(spriteTrainee);
}


Missile::~Missile() {
	// VIDE
}
