/*
 * ProjectileExplosif.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "ProjectileExplosif.h"


ProjectileExplosif::ProjectileExplosif(Coordonnees tCoord, Personnage* tCible, int tDommages, int tRayonExplosion) :
	Projectile(tCoord, tCible, tDommages), rayonExplosion(tRayonExplosion) {
	vitesse = 20;
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	textureProjectile = pResourcesLoader->textureProjectileExplosif;
	spriteProjectile.setTexture(textureProjectile);
	spriteProjectile.setScale(0.5,0.5);
	spriteProjectile.setPosition(tCoord.posX,tCoord.posY);
}

void ProjectileExplosif::toucherEnnemi()
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
}

void ProjectileExplosif::dessiner(sf::RenderWindow & rWindow){
	rWindow.draw(spriteProjectile);
}


ProjectileExplosif::~ProjectileExplosif() {
	// TODO Auto-generated destructor stub
}

void ProjectileExplosif::avancer()
{
	int xproj = this->coordonnees.getPosX();
	int yproj = this->coordonnees.getPosY();
	int xperso = this->cible->getCoordonnees().getPosX() + 12;
	int yperso = this->cible->getCoordonnees().getPosY() + 20;

	double alpha = this->vitesse/sqrt(pow((float)(xperso-xproj),2)+pow((float)(yperso-yproj),2));
	if (alpha > 1)
	{
		// Si alpha > 1, cela veut dire que le projectile s'apprete a parcourir une
		// distance plus grande que celle qui le separe de la cible
		alpha = 1;
	}
	xproj += (int)floor(alpha*(xperso-xproj));
	yproj += (int)floor(alpha*(yperso-yproj));
	this->coordonnees.setPosX(xproj);
	this->coordonnees.setPosY(yproj);
	spriteProjectile.setPosition(xproj, yproj);

	if(((xperso-xproj)+(yperso-yproj)) == 0){
		this->toucherEnnemi();
	}
}

