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
class Personnage;

class ResourceManager {

public:
    ~ResourceManager();
    static ResourceManager* getInstance();

    // Add
    void addTour(Tour* entite);
    void addProjectile(Projectile* entite);
    void addPersonnage(Personnage* entite);
	void addObjetAnnexe(ElementGraphique* objetAnnexe);
    void addCarte(Carte* carte);
    void addVague(Vague* vague);
    void addRessources(Ressources* ressources);
    void addGenerateurVague(GenerateurVague* generateurVague);
    void addPersoFictif(Personnage* pPersoFictif);

    // Remove
    void clearResourcesManager();

    void removeProjectile(Projectile* entite);
    void removePersonnage(Personnage* entite);
    void removeTour(Tour* entite);
	void removeObjetAnnexe(ElementGraphique* objetAnnexe);

    // Get
    vector<Tour*> getTour();
    vector<Personnage*> getPersonnage();
    vector<Projectile*> getProjectile();
	vector<ElementGraphique*> getObjetAnnexe();
    Carte* getCarte();
    Vague* getVague();
    Ressources* getRessources();
    GenerateurVague* getGenerateurVague();
    Tour* getTourSelectionnee();
    Personnage* getPersoFictif();

    // Set

    void setTourSelectionnee(Tour* tour);

    //TODO choisir entre public et private, si public, methodes get inutiles
private:
    ResourceManager();

    vector<Tour*> tourConteneur;
    vector<Projectile*> projectileConteneur;
    vector<Personnage*> personnageConteneur;
	vector<ElementGraphique*> objetAnnexeConteneur;
    Carte* cartePointeur;
    Vague* vaguePointeur;
    Ressources* ressourcesPointeur;
    GenerateurVague* vagueGenerateurPointeur;
    Tour* tourSelectionnee;
	Personnage * pPersoFictif;

};

#endif /* RESOURCEMANAGER_H_ */
