/*
 * ResourceManager.h
 *
 *  Created on: 13 nov. 2013
 *      Author: francois
 */

#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <vector>
#include "elements/Menu.h"
#include "elements/Projectile.h"
#include "elements/Tour.h"
#include "elements/Personnage.h"
#include "elements/Carte.h"

using namespace std;

class ResourceManager {

public:
    ~ResourceManager();
    static ResourceManager* getInstance();
    void addTour(Tour* entite);
    void addProjectile(Projectile* entite);
    void addPersonnage(Personnage* entite);
    void addMenu(Menu* menu);
    void addCarte(Carte* carte);
    vector<Tour*> getTour();
    vector<Personnage*> getPersonnage();
    vector<Projectile*> getProjectile();
    Menu* getMenu();
    Carte* getCarte();
private:
    ResourceManager();
    vector<Tour*> TourConteneur;
    vector<Projectile*> ProjectileConteneur;
    vector<Personnage*> PersonnageConteneur;
    Menu* MenuPointeur;
    Carte* CartePointeur;
};

#endif /* RESOURCEMANAGER_H_ */
