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
#include "elements/Batiment.h"
#include "elements/Batiments/Tour.h"
#include "elements/Carte.h"
#include "elements/Menu.h"
#include "elements/Ressources.h"


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
    void addBatiment(Batiment* entite);
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
    void removeBatiment(Batiment* entite);
	void removeObjetAnnexe(ElementGraphique* objetAnnexe);

    // Get
    std::vector<Batiment*> getBatiment();
    std::vector<Personnage*> getPersonnage();
    std::vector<Projectile*> getProjectile();
	std::vector<ElementGraphique*> getObjetAnnexe();
    Carte* getCarte();
    Vague* getVague();
    Ressources* getRessources();
    GenerateurVague* getGenerateurVague();
    Batiment* getBatimentSelectionne();
    Personnage* getPersoFictif();

    // Set

    void setBatimentSelectionne(Batiment* tour);

private:
    ResourceManager();

    std::vector<Batiment*> batimentConteneur;
    std::vector<Projectile*> projectileConteneur;
    std::vector<Personnage*> personnageConteneur;
	std::vector<ElementGraphique*> objetAnnexeConteneur;
    Carte* cartePointeur;
    Vague* vaguePointeur;
    Ressources* ressourcesPointeur;
    GenerateurVague* vagueGenerateurPointeur;
    Batiment* batimentSelectionne;
	Personnage * pPersoFictif;

};

#endif /* RESOURCEMANAGER_H_ */
