/*
 * ResourcesLoader.cpp
 *
 *  TowerDefense ECP
 *
 * Cette classe est destinee a charger tout ce qui est dans le dossier resources/,
 * c'est-a-dire la police, les sons et les textures.
 * Les objets crees par la suite viennent chercher ce dont ils ont besoin dans cette fonction.
 *      
 */

#include "ResourcesLoader.h"
#define NULL 0 

// Pointeur vers l'unique instance du ResourceLoader
ResourcesLoader* pResourcesLoader = NULL;
// ResourcesLoaderInstance = true si une instance existe deja
bool ResourcesLoaderInstance = false;

// Retourne le pointeur du ResourceLoader
ResourcesLoader* ResourcesLoader::getInstance() {
    if (!ResourcesLoaderInstance)
    {
        pResourcesLoader = new ResourcesLoader();
        ResourcesLoaderInstance = true;
        return pResourcesLoader;
    }
    else
    {
        return pResourcesLoader;
    }
}

ResourcesLoader::ResourcesLoader() {

}

ResourcesLoader::~ResourcesLoader() {
	// TODO Auto-generated destructor stub
}
// Charge toutes les textures
void ResourcesLoader::ChargerTextures() {
	textureMenu.loadFromFile("resources/textures/menu.png");

	texturePersonnage.loadFromFile("resources/textures/texturePersonnage.jpg");
	texturePersonnageDoubleGauche.loadFromFile("resources/textures/PersonnageDoubleGauche.png");
	texturePersonnageDoubleDroite.loadFromFile("resources/textures/PersonnageDoubleDroite.png");
	texturePersonnageDoubleBas.loadFromFile("resources/textures/PersonnageDoubleBas.png");
	texturePersonnageDoubleHaut.loadFromFile("resources/textures/PersonnageDoubleHaut.png");
	texturePersonnageBasiqueGauche.loadFromFile("resources/textures/PersonnageBasiqueGauche.png");
	texturePersonnageBasiqueDroite.loadFromFile("resources/textures/PersonnageBasiqueDroite.png");
	texturePersonnageBasiqueBas.loadFromFile("resources/textures/PersonnageBasiqueBas.png");
	texturePersonnageBasiqueHaut.loadFromFile("resources/textures/PersonnageBasiqueHaut.png");
	texturePersonnageGenerateurGauche.loadFromFile("resources/textures/PersonnageGenerateurGauche.png");
	texturePersonnageGenerateurDroite.loadFromFile("resources/textures/PersonnageGenerateurDroite.png");
	texturePersonnageGenerateurBas.loadFromFile("resources/textures/PersonnageGenerateurBas.png");
	texturePersonnageGenerateurHaut.loadFromFile("resources/textures/PersonnageGenerateurHaut.png");
	texturePersonnageVolantGauche.loadFromFile("resources/textures/PersonnageVolantGauche.png");
	texturePersonnageVolantDroite.loadFromFile("resources/textures/PersonnageVolantDroite.png");
	texturePersonnageVolantBas.loadFromFile("resources/textures/PersonnageVolantBas.png");
	texturePersonnageVolantHaut.loadFromFile("resources/textures/PersonnageVolantHaut.png");
	texturePersonnageAccelerantGauche.loadFromFile("resources/textures/PersonnageAccelerantGauche.png");
	texturePersonnageAccelerantDroite.loadFromFile("resources/textures/PersonnageAccelerantDroite.png");
	texturePersonnageAccelerantBas.loadFromFile("resources/textures/PersonnageAccelerantBas.png");
	texturePersonnageAccelerantHaut.loadFromFile("resources/textures/PersonnageAccelerantHaut.png");

	// boss
	textureSuperPersonnage.loadFromFile("resources/textures/SuperPersonnage.png");


	textureCarte.loadFromFile("resources/textures/champDeBataille.jpg");
	textureCanonLourd.loadFromFile("resources/textures/textureCanonLourd.png");
	textureTourAttaqueBasique.loadFromFile("resources/textures/textureTourAttaqueBasique.png");
	textureTourSupport.loadFromFile("resources/textures/textureTourSupport.png");
	textureProjectileBasique.loadFromFile("resources/textures/textureProjectileBasique.png");
	textureProjectileExplosif.loadFromFile("resources/textures/textureProjectileExplosif.png");
	textureRessources.loadFromFile("resources/textures/textureResources.jpg");
	textureLevelUpBouton.loadFromFile("resources/textures/textureLevelUpBouton.png");
	textureSellBouton.loadFromFile("resources/textures/textureSellBouton.png");
	textureMur.loadFromFile("resources/textures/textureMur.png");
	textureSelection.loadFromFile("resources/textures/cercleSelection.png");
	// textures missile
	textureTraineeMissile1.loadFromFile("resources/textures/traineeMissile1.png");
	textureTraineeMissile2.loadFromFile("resources/textures/traineeMissile2.png");
	textureTraineeMissile3.loadFromFile("resources/textures/traineeMissile3.png");
	textureTraineeMissile4.loadFromFile("resources/textures/traineeMissile4.png");
	textureTraineeMissile5.loadFromFile("resources/textures/traineeMissile5.png");
	textureTraineeMissile6.loadFromFile("resources/textures/traineeMissile6.png");
	textureTraineeMissile7.loadFromFile("resources/textures/traineeMissile7.png");
	textureTraineeMissile8.loadFromFile("resources/textures/traineeMissile8.png");
	textureTraineeMissile9.loadFromFile("resources/textures/traineeMissile9.png");
	textureMissile.loadFromFile("resources/textures/missile.png");
	textureExplosionMissile1.loadFromFile("resources/textures/impactMissile1.png");
	textureExplosionMissile2.loadFromFile("resources/textures/impactMissile2.png");
	textureExplosionMissile3.loadFromFile("resources/textures/impactMissile3.png");
	textureExplosionMissile4.loadFromFile("resources/textures/impactMissile4.png");
	textureExplosionMissile5.loadFromFile("resources/textures/impactMissile5.png");
	textureExplosionMissile6.loadFromFile("resources/textures/impactMissile6.png");
	textureExplosionMissile7.loadFromFile("resources/textures/impactMissile7.png");
	textureExplosionMissile8.loadFromFile("resources/textures/impactMissile8.png");
	textureExplosionMissile9.loadFromFile("resources/textures/impactMissile9.png");
	textureExplosionMissile10.loadFromFile("resources/textures/impactMissile10.png");
	// TourDeGlace
	textureTourDeGlace.loadFromFile("resources/textures/frostTower.png");
	textureEnvironnementGlace.loadFromFile("resources/textures/frostEnvironement.png");
	textureTirDeGlace.loadFromFile("resources/textures/frostTir.png");

}
// Charge tous les sons
void ResourcesLoader::ChargerSons() {
	musique.openFromFile("resources/sons/musicTest.ogg");
	bufferCreationTour.loadFromFile("resources/sons/creationTour.ogg");
	bufferTirTourAttaqueBasique.loadFromFile("resources/sons/tirTourAttaqueBasique.ogg");
	bufferTirCanonLourd.loadFromFile("resources/sons/tirCanonLourd.ogg");
	bufferTirTourGlace.loadFromFile("resources/sons/tirTourGlace.ogg");
}
// Charge toutes les polices
void ResourcesLoader::ChargerPolices() {
	policeMenu.loadFromFile("resources/polices/Capture it.ttf");
	policeTableauDeBord.loadFromFile("resources/polices/animeace2_reg.ttf");
}
