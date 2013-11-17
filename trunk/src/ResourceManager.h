/*
 * ResourceManager.h
 *
 *  TowerDefense ECP
 *      
 */

#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <vector>
#include <algorithm>
#include "elements/Tour.h"
#include "elements/Carte.h"
#include "elements/Menu.h"
#include "elements/Ressources.h"

using namespace std;

// Forward Declaration to avoid includes issues
class Projectile;
class Personnage;
class GenerateurVague;
class Vague;

class ResourceManager {

public:
    ~ResourceManager();
    static ResourceManager* getInstance();

    // Add
    void addTour(Tour* entite);
    void addProjectile(Projectile* entite);
    void addPersonnage(Personnage* entite);
    void addMenu(Menu* menu);
    void addCarte(Carte* carte);
    void addVague(Vague* vague);
    void addRessources(Ressources* ressources);
    void addGenerateurVague(GenerateurVague* generateurVague);

    // Remove

    void removeProjectile(Projectile* entite);
    void removePersonnage(Personnage* entite);

    // Get
    vector<Tour*> getTour();
    vector<Personnage*> getPersonnage();
    vector<Projectile*> getProjectile();
    Menu* getMenu();
    Carte* getCarte();
    Vague* getVague();
    Ressources* getRessources();
    GenerateurVague* getGenerateurVague();

    vector<Tour*> tourConteneur;
    vector<Projectile*> projectileConteneur;
    vector<Personnage*> personnageConteneur;
    Menu* menuPointeur;
    Carte* cartePointeur;
    Vague* vaguePointeur;
    Ressources* ressourcesPointeur;
    GenerateurVague* vagueGenerateurPointeur;
private:
    ResourceManager();

};

#endif /* RESOURCEMANAGER_H_ */
