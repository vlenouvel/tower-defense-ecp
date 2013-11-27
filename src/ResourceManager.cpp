/*
 * ResourceManager.cpp
 *
 *  TowerDefense ECP
 *
 *  Cette classe, qui utilise le pattern Singleton, stocke les pointeurs de l'ensemble
 *  des elements de jeu afin de les rendre facilement accessibles au travers du programme.
 *      
 */

#include "ResourceManager.h"

// Pointeur vers l'unique instance du ResourceManager
ResourceManager* managerPointeur = 0;
// instance = true si une instance existe deja
bool instance = false;

// Retourne le pointeur du ResourceManager (cree un objet de type ResourceManager s'il n'existe pas deja)
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
    vector<Batiment*> tourConteneur;
    vector<Personnage*> personnageConteneur;
    vector<Projectile*> projectileConteneur;
    cartePointeur = 0;
    ressourcesPointeur = 0;
    vaguePointeur = 0;
    vagueGenerateurPointeur = 0;
    batimentSelectionne = 0;
    pPersoFictif = 0;
}

ResourceManager::~ResourceManager() {
	delete managerPointeur;
	instance = false;
}

void ResourceManager::clearResourcesManager()
{
	cartePointeur = 0;
    ressourcesPointeur = 0;
    vaguePointeur = 0;
    vagueGenerateurPointeur = 0;
    batimentSelectionne = 0;
    batimentConteneur.clear();
    personnageConteneur.clear();
    projectileConteneur.clear();
}

// Batiment
void ResourceManager::addBatiment(Batiment* entite) {
	batimentConteneur.push_back(entite);
}

vector<Batiment*> ResourceManager::getBatiment() {
	return batimentConteneur;
}

void ResourceManager::addObjetAnnexe(ElementGraphique* objetAnnexe){
	objetAnnexeConteneur.push_back(objetAnnexe);
}

vector<ElementGraphique*> ResourceManager::getObjetAnnexe(){
	return objetAnnexeConteneur;
}

void ResourceManager::removeBatiment(Batiment* entite)
{
	batimentConteneur.erase(remove(batimentConteneur.begin(), batimentConteneur.end(), entite), batimentConteneur.end());
}
void ResourceManager::removeObjetAnnexe(ElementGraphique* objetAnnexe)
{
	objetAnnexeConteneur.erase(remove(objetAnnexeConteneur.begin(), objetAnnexeConteneur.end(), objetAnnexe), objetAnnexeConteneur.end());
}

// Personnage
void ResourceManager::addPersonnage(Personnage* entite) {
	personnageConteneur.push_back(entite);
}

vector<Personnage*> ResourceManager::getPersonnage() {
	return personnageConteneur;
}

void ResourceManager::removePersonnage(Personnage *entite){
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

// Carte
void ResourceManager::addCarte(Carte* carte) {
	if(cartePointeur != 0)
		delete cartePointeur;
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

// Ressources

void ResourceManager::addRessources(Ressources* ressources)
{
	ressourcesPointeur = ressources;
}

Ressources* ResourceManager::getRessources()
{
	return ressourcesPointeur;
}

// Batiment selectionnee
Batiment* ResourceManager::getBatimentSelectionne()
{
	return batimentSelectionne;
}

void ResourceManager::setBatimentSelectionne(Batiment* tour)
{
	batimentSelectionne = tour;
}

// Personnage Fictif

void ResourceManager::addPersoFictif(Personnage* pPerso) {
	pPersoFictif = pPerso;
}

Personnage* ResourceManager::getPersoFictif() {
	return pPersoFictif;
}
