/*
 * ResourcesLoader.cpp
 *
 *  TowerDefense ECP
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
	textureCarte.loadFromFile("resources/textures/champDeBataille.jpg");
	textureCanonLourd.loadFromFile("resources/textures/textureCanonLourd.jpg");
	textureTourAttaqueBasique.loadFromFile("resources/textures/textureTourAttaqueBasique.jpg");
	textureProjectileBasique.loadFromFile("resources/textures/textureProjectileBasique.png");
	textureProjectileExplosif.loadFromFile("resources/textures/textureProjectileExplosif.png");
	textureRessources.loadFromFile("resources/textures/textureResources.jpg");
	textureLevelUpBouton.loadFromFile("resources/textures/textureLevelUpBouton.png");
	textureSellBouton.loadFromFile("resources/textures/textureSellBouton.png");
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

}
// Charge tous les sons
void ResourcesLoader::ChargerSons() {
	musique.openFromFile("resources/sons/musicTest.ogg");
	bufferCreationTour.loadFromFile("resources/sons/creationTour.ogg");
	bufferTirTourAttaqueBasique.loadFromFile("resources/sons/tirTourAttaqueBasique.ogg");
	bufferTirCanonLourd.loadFromFile("resources/sons/tirCanonLourd.ogg");
}
// Charge toutes les polices
void ResourcesLoader::ChargerPolices() {
	policeMenu.loadFromFile("resources/polices/Capture it.ttf");
	policeTableauDeBord.loadFromFile("resources/polices/animeace2_reg.ttf");
}
