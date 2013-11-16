/*
 * ResourceManager.h
 *
 *  Created on: 13 nov. 2013
 *      Author: francois
 */

#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <vector>
#include "elements/Personnage.h"
#include "elements/Tour.h"
#include "elements/Carte.h"
#include "elements/Projectile.h"
#include "elements/Menu.h"

using namespace std;

// Forward Declaration to avoid includes issues
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
    void addGenerateurVague(GenerateurVague* generateurVague);

    // Remove

    void removeProjectile(Projectile* entite);

    // Get
    vector<Tour*> getTour();
    vector<Personnage*> getPersonnage();
    vector<Projectile*> getProjectile();
    Menu* getMenu();
    Carte* getCarte();
    Vague* getVague();
    GenerateurVague* getGenerateurVague();
private:
    ResourceManager();
    vector<Tour*> tourConteneur;
    vector<Projectile*> projectileConteneur;
    vector<Personnage*> personnageConteneur;
    Menu* menuPointeur;
    Carte* cartePointeur;
    Vague* vaguePointeur;
    GenerateurVague* vagueGenerateurPointeur;
};

#endif /* RESOURCEMANAGER_H_ */
