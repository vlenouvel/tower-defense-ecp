/*
 * ExplosionMissile.cpp
 *
 *  TowerDefense ECP
 *       
 */

#include "ExplosionMissile.h"


ExplosionMissile::ExplosionMissile(Coordonnees tCoord){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	spriteExplosion.setTexture(pResourcesLoader->textureExplosionMissile1);
	spriteExplosion.setPosition(tCoord.posX-40,tCoord.posY-40);
	momentDuCycle = 0;
}


void ExplosionMissile::dessiner(sf::RenderWindow & rWindow){
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	ResourceManager *manager = ResourceManager::getInstance();
	switch(momentDuCycle){
		case 2:
			spriteExplosion.setTexture(pResourcesLoader->textureExplosionMissile2);
			break;
		case 4:
			spriteExplosion.setTexture(pResourcesLoader->textureExplosionMissile3);
			break;
		case 6:
			spriteExplosion.setTexture(pResourcesLoader->textureExplosionMissile4);
			break;
		case 8:
			spriteExplosion.setTexture(pResourcesLoader->textureExplosionMissile5);
			break;
		case 10:
			spriteExplosion.setTexture(pResourcesLoader->textureExplosionMissile6);
			break;
		case 12:
			spriteExplosion.setTexture(pResourcesLoader->textureExplosionMissile7);
			break;
		case 14:
			spriteExplosion.setTexture(pResourcesLoader->textureExplosionMissile8);
			break;
		case 16:
			spriteExplosion.setTexture(pResourcesLoader->textureExplosionMissile9);
			break;
		case 18:
			spriteExplosion.setTexture(pResourcesLoader->textureExplosionMissile10);
			break;
		default:
			break;
	}
	momentDuCycle++;
	rWindow.draw(spriteExplosion);
	if (momentDuCycle > 20){
		manager->removeObjetAnnexe(this);
		delete this;
	}
}


ExplosionMissile::~ExplosionMissile() {
	// TODO Auto-generated destructor stub
}
