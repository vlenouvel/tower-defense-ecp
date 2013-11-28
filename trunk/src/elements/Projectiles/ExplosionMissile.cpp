/*
 * ExplosionMissile.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "ExplosionMissile.h"


ExplosionMissile::ExplosionMissile(Coordonnees tCoord){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spriteElement.setTexture(pResourcesLoader->textureExplosionMissile1);
	spriteElement.setPosition(tCoord.getPosX()-40,tCoord.getPosY()-40);
	momentDuCycle = 0;
}


void ExplosionMissile::dessiner(sf::RenderWindow & rWindow){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	ResourceManager *manager = ResourceManager::getInstance();
	switch(momentDuCycle){
		case 2:
			spriteElement.setTexture(pResourcesLoader->textureExplosionMissile2);
			break;
		case 4:
			spriteElement.setTexture(pResourcesLoader->textureExplosionMissile3);
			break;
		case 6:
			spriteElement.setTexture(pResourcesLoader->textureExplosionMissile4);
			break;
		case 8:
			spriteElement.setTexture(pResourcesLoader->textureExplosionMissile5);
			break;
		case 10:
			spriteElement.setTexture(pResourcesLoader->textureExplosionMissile6);
			break;
		case 12:
			spriteElement.setTexture(pResourcesLoader->textureExplosionMissile7);
			break;
		case 14:
			spriteElement.setTexture(pResourcesLoader->textureExplosionMissile8);
			break;
		case 16:
			spriteElement.setTexture(pResourcesLoader->textureExplosionMissile9);
			break;
		case 18:
			spriteElement.setTexture(pResourcesLoader->textureExplosionMissile10);
			break;
		default:
			break;
	}
	momentDuCycle++;
	rWindow.draw(spriteElement);
	if (momentDuCycle > 20){
		manager->removeObjetAnnexe(this);
		delete this;
	}
}


ExplosionMissile::~ExplosionMissile() {
	// VIDE
}
