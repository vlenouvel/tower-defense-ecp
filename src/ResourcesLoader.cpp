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
	ChargerTextures();
	ChargerSons();
	ChargerPolices();
}

ResourcesLoader::~ResourcesLoader() {
	// TODO Auto-generated destructor stub
}
// Charge toutes les textures
void ResourcesLoader::ChargerTextures() {
	texturePersonnage.loadFromFile("resources/textures/texturePersonnage.jpg");
	textureCarte.loadFromFile("resources/textures/champDeBataille.jpg");
	textureCanonLourd.loadFromFile("resources/textures/textureCanonLourd.jpg");
	textureTourAttaqueBasique.loadFromFile("resources/textures/textureTourAttaqueBasique.jpg");
	textureProjectileBasique.loadFromFile("resources/textures/textureProjectileBasique.png");
	textureProjectileExplosif.loadFromFile("resources/textures/textureProjectileExplosif.png");
	textureRessources.loadFromFile("resources/textures/textureResources.jpg");

}
// Charge tous les sons
void ResourcesLoader::ChargerSons() {
	musique.openFromFile("resources/sons/musicTest.ogg");
}
// Charge toutes les polices
void ResourcesLoader::ChargerPolices() {
	police.loadFromFile("resources/polices/Capture it.ttf");
}