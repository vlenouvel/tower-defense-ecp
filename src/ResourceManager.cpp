/*
 * ResourceManager.cpp
 *
 *  Created on: 13 nov. 2013
 *      Author: francois
 */

#include "ResourceManager.h"

// Pointeur vers l'unique instance du ResourceManager
ResourceManager* managerPointeur = NULL;
// instance = true si une instance existe deja
bool instance = false;

// Retourne le pointeur du ResourceManager
ResourceManager* ResourceManager::getInstance() {
    if (!instance)
    {
        managerPointeur = new ResourceManager();
        instance = true;
        return managerPointeur;
    }
    else
    {
        return managerPointeur;
    }
}

ResourceManager::ResourceManager() {
    vector<Tour*> TourConteneur;
    vector<Personnage*> PersonnageConteneur;
    vector<Projectile*> ProjectileConteneur;
    MenuPointeur = NULL;
    CartePointeur = NULL;
}

ResourceManager::~ResourceManager() {
	delete managerPointeur;
}

// Tour
void ResourceManager::addTour(Tour* entite) {
	TourConteneur.push_back(entite);
}

vector<Tour*> ResourceManager::getTour() {
	return TourConteneur;
}

// Personnage
void ResourceManager::addPersonnage(Personnage* entite) {
	PersonnageConteneur.push_back(entite);
}

vector<Personnage*> ResourceManager::getPersonnage() {
	return PersonnageConteneur;
}

// Projectile
void ResourceManager::addProjectile(Projectile* entite) {
	ProjectileConteneur.push_back(entite);
}

vector<Projectile*> ResourceManager::getProjectile() {
	return ProjectileConteneur;
}

// Menu
void ResourceManager::addMenu(Menu* menu) {
	MenuPointeur = menu;
}

Menu* ResourceManager::getMenu() {
	return MenuPointeur;
}

// Carte
void ResourceManager::addCarte(Carte* carte) {
	CartePointeur = carte;
}

Carte* ResourceManager::getCarte() {
	return CartePointeur;
}

