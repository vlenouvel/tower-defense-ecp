/*
 * Personnage.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#include "Personnage.h"
#include <iostream>
#include <exception>

Personnage::Personnage(int tVie, int tVitesse, int tArmure, Coordonnees tCoord) :
		vie(tVie), vitesse(tVitesse), armure(tArmure), coordonnees(tCoord)
{
	ResourcesLoader* pResourcesLoader = ResourcesLoader::getInstance();
	texturePersonnage = pResourcesLoader->texturePersonnage;
	spritePersonnage.setTexture(texturePersonnage);
	spritePersonnage.setScale(0.5,0.5);
	spritePersonnage.setPosition(tCoord.posX,tCoord.posY);
}

void Personnage::agir()
{
	this->avancer();
}

void Personnage::avancer()
{
	int actuelleAbscisse = coordonnees.getPosX();
	coordonnees.setPosX(actuelleAbscisse + vitesse);
	if(coordonnees.getPosX() > 800)
		coordonnees.setPosX(0);
	spritePersonnage.setPosition(coordonnees.posX,coordonnees.posY);
}

void Personnage::perdrePV(int degat)
{
	if(degat > armure){
		vie -= (degat - armure);
		if(vie <= 0)
		{
			this->mourir();
		}
	}
}

void Personnage::mourir()
{
	ResourceManager *manager = ResourceManager::getInstance();
	manager->removePersonnage(this);

	// Also remove all projectiles going for that personnage
	std::vector<Projectile*> projectileConteneur = manager->getProjectile();
	vector<Projectile*>::iterator projectileIterator;
	for(projectileIterator = projectileConteneur.begin() ; projectileIterator!= projectileConteneur.end() ; projectileIterator++)
	{
		Projectile* pProjo = *projectileIterator;
		if(pProjo->getCible() == this)
		{
			manager->removeProjectile(pProjo);
			// TODO : Supprimer le vrai projo de la mémoire ...
			//delete pProjo;
			pProjo->setCible(0);
		}
	}
	delete this;
}

Personnage::~Personnage() {
	// TODO Auto-generated destructor stub
}

void Personnage::dessiner(sf::RenderWindow &pWindow){
	pWindow.draw(spritePersonnage);
}

int Personnage::getVie()
{
	return this->vie;
}

Coordonnees Personnage::getCoordonnees()
{
	return this->coordonnees;
}
