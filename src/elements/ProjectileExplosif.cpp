/*
 * ProjectileExplosif.cpp
 *
 *  Created on: 14 nov. 2013
 *      Author: Vincent Lenouvel
 */

#include "ProjectileExplosif.h"


ProjectileExplosif::ProjectileExplosif(Coordonnees tCoord, Personnage* tCible, int tDommages, int tRayonExplosion) :
	Projectile(tCoord, tCible, tDommages), rayonExplosion(tRayonExplosion) {
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

