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
    void addMenu(Menu* menu);
    void addCarte(Carte* carte);
    void addVague(Vague* vague);
    void addRessources(Ressources* ressources);
    void addGenerateurVague(GenerateurVague* generateurVague);
    //void addEtatJeu(EtatJeu* EtatJeu);

    // Remove

    void removeProjectile(Projectile* entite);
    void removePersonnage(Personnage* entite);
    void removeTour(Tour* entite);
	void removeObjetAnnexe(ElementGraphique* objetAnnexe);

    // Get
    vector<Tour*> getTour();
    vector<Personnage*> getPersonnage();
    vector<Projectile*> getProjectile();
	vector<ElementGraphique*> getObjetAnnexe();
    Menu* getMenu();
    Carte* getCarte();
    Vague* getVague();
    Ressources* getRessources();
    GenerateurVague* getGenerateurVague();
    Tour* getTourSelectionnee();
    //EtatJeu* getEtatJeu();

    // Set

    void setTourSelectionnee(Tour* tour);


    vector<Tour*> tourConteneur;
    vector<Projectile*> projectileConteneur;
    vector<Personnage*> personnageConteneur;
	vector<ElementGraphique*> objetAnnexeConteneur;
    Menu* menuPointeur;
    Carte* cartePointeur;
    Vague* vaguePointeur;
    Ressources* ressourcesPointeur;
    GenerateurVague* vagueGenerateurPointeur;
    //EtatJeu* pEtatJeu;
    Tour* tourSelectionnee;
	Personnage * pPersoFictif;

    //TODO choisir entre public et private, si public, methodes get inutiles
private:
    ResourceManager();

};

#endif /* RESOURCEMANAGER_H_ */
