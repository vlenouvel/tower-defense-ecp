/*
 * ProjectileBasique.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "ProjectileBasique.h"

ProjectileBasique::ProjectileBasique(Coordonnees tCoord, Personnage* tCible, int tDommages) : Projectile(tCoord, tCible, tDommages) {
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	textureProjectile = pResourcesLoader->textureProjectileBasique;
	spriteProjectile.setTexture(textureProjectile);
	spriteProjectile.setScale(0.5,0.5);
	spriteProjectile.setPosition(tCoord.posX,tCoord.posY);
}

void ProjectileBasique::toucherEnnemi()
{
	cible->perdrePV(dommages);
	ResourceManager *manager = ResourceManager::getInstance();
	manager->removeProjectile(this);
}

void ProjectileBasique::dessiner(sf::RenderWindow & rWindow){
	rWindow.draw(spriteProjectile);
}


ProjectileBasique::~ProjectileBasique() {
	// TODO Auto-generated destructor stub
}

