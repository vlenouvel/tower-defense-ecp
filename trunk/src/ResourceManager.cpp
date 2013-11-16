/*
 * ResourceManager.cpp
 *
 *  TowerDefense ECP
 *      
 */

#include "ResourceManager.h"

// Pointeur vers l'unique instance du ResourceManager
ResourceManager* managerPointeur = 0;
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
    vector<Tour*> tourConteneur;
    vector<Personnage*> personnageConteneur;
    vector<Projectile*> projectileConteneur;
    menuPointeur = 0;
    cartePointeur = 0;
    vaguePointeur = 0;
    vagueGenerateurPointeur = 0;
}

ResourceManager::~ResourceManager() {
	delete managerPointeur;
}

// Tour
void ResourceManager::addTour(Tour* entite) {
	tourConteneur.push_back(entite);
}

vector<Tour*> ResourceManager::getTour() {
	return tourConteneur;
}

// Personnage
void ResourceManager::addPersonnage(Personnage* entite) {
	personnageConteneur.push_back(entite);
}

vector<Personnage*> ResourceManager::getPersonnage() {
	return personnageConteneur;
}

void ResourceManager::removePersonnage(Personnage *entite){
	// Remove the personnage
	personnageConteneur.erase(remove(personnageConteneur.begin(), personnageConteneur.end(), entite), personnageConteneur.end());
}

// Projectile
void ResourceManager::addProjectile(Projectile* entite) {
	projectileConteneur.push_back(entite);
}

vector<Projectile*> ResourceManager::getProjectile() {
	return projectileConteneur;
}

void ResourceManager::removeProjectile(Projectile *entite){
	projectileConteneur.erase(remove(projectileConteneur.begin(), projectileConteneur.end(), entite), projectileConteneur.end());
}

// Menu
void ResourceManager::addMenu(Menu* menu) {
	menuPointeur = menu;
}

Menu* ResourceManager::getMenu() {
	return menuPointeur;
}

// Carte
void ResourceManager::addCarte(Carte* carte) {
	cartePointeur = carte;
}

Carte* ResourceManager::getCarte() {
	return cartePointeur;
}

// Vague
void ResourceManager::addVague(Vague* vague)
{
	vaguePointeur = vague;
}

Vague* ResourceManager::getVague()
{
	return vaguePointeur;
}

// Generateur Vague

void ResourceManager::addGenerateurVague(GenerateurVague* generateurVague)
{
	vagueGenerateurPointeur = generateurVague;
}

GenerateurVague* ResourceManager::getGenerateurVague()
{
	return vagueGenerateurPointeur;
}
