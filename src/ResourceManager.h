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

// Forward Declaration
class Projectile;
class Personnage;
class GenerateurVague;
class Vague;
class EtatJeu;

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
    //void addEtatJeu(EtatJeu* EtatJeu);

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
    //EtatJeu* getEtatJeu();

    vector<Tour*> tourConteneur;
    vector<Projectile*> projectileConteneur;
    vector<Personnage*> personnageConteneur;
    Menu* menuPointeur;
    Carte* cartePointeur;
    Vague* vaguePointeur;
    Ressources* ressourcesPointeur;
    GenerateurVague* vagueGenerateurPointeur;
    //EtatJeu* pEtatJeu;

private:
    ResourceManager();

};

#endif /* RESOURCEMANAGER_H_ */
