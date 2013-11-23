/*
 * ResourcesLoader.h
 *
 *  TowerDefense ECP
 *
 * Cette classe est destinee a charger tout ce qui est dans le dossier resources/,
 * c'est-a-dire la police, les sons et les textures.
 * Les objets crees par la suite viennent chercher ce dont ils ont besoin dans cette fonction.
 *      
 */

#ifndef RESOURCESLOADER_H_
#define RESOURCESLOADER_H_
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


/* */

class ResourcesLoader {
public:
	ResourcesLoader();
	virtual ~ResourcesLoader();

	static ResourcesLoader* getInstance();

	void ChargerTextures();
	void ChargerSons();
	void ChargerPolices();

	sf::Texture textureMenu;
	sf::Texture texturePersonnage;
	sf::Texture texturePersonnageDoubleGauche;
	sf::Texture texturePersonnageDoubleDroite;
	sf::Texture texturePersonnageDoubleHaut;
	sf::Texture texturePersonnageDoubleBas;
	sf::Texture texturePersonnageBasiqueGauche;
	sf::Texture texturePersonnageBasiqueDroite;
	sf::Texture texturePersonnageBasiqueHaut;
	sf::Texture texturePersonnageBasiqueBas;
	sf::Texture texturePersonnageGenerateurGauche;
	sf::Texture texturePersonnageGenerateurDroite;
	sf::Texture texturePersonnageGenerateurHaut;
	sf::Texture texturePersonnageGenerateurBas;
	sf::Texture texturePersonnageVolantGauche;
	sf::Texture texturePersonnageVolantDroite;
	sf::Texture texturePersonnageVolantHaut;
	sf::Texture texturePersonnageVolantBas;
	sf::Texture texturePersonnageAccelerantGauche;
	sf::Texture texturePersonnageAccelerantDroite;
	sf::Texture texturePersonnageAccelerantHaut;
	sf::Texture texturePersonnageAccelerantBas;
	sf::Texture textureSuperPersonnage;
	sf::Texture textureCarte;
	sf::Texture textureCanonLourd;
	sf::Texture textureTourAttaqueBasique;
	sf::Texture textureTourSupport;
	sf::Texture textureProjectileBasique;
	sf::Texture textureProjectileExplosif;
	sf::Texture textureRessources;
	sf::Texture textureLevelUpBouton;
	sf::Texture textureSellBouton;
	sf::Texture textureMur;
	sf::Texture textureSelection;
	// Missile
	sf::Texture textureTraineeMissile1;
	sf::Texture textureTraineeMissile2;
	sf::Texture textureTraineeMissile3;
	sf::Texture textureTraineeMissile4;
	sf::Texture textureTraineeMissile5;
	sf::Texture textureTraineeMissile6;
	sf::Texture textureTraineeMissile7;
	sf::Texture textureTraineeMissile8;
	sf::Texture textureTraineeMissile9;
	sf::Texture textureMissile;
	sf::Texture textureExplosionMissile1;
	sf::Texture textureExplosionMissile2;
	sf::Texture textureExplosionMissile3;
	sf::Texture textureExplosionMissile4;
	sf::Texture textureExplosionMissile5;
	sf::Texture textureExplosionMissile6;
	sf::Texture textureExplosionMissile7;
	sf::Texture textureExplosionMissile8;
	sf::Texture textureExplosionMissile9;
	sf::Texture textureExplosionMissile10;
	// TourDeGlace
	sf::Texture textureTourDeGlace;
	sf::Texture textureEnvironnementGlace;
	sf::Texture textureTirDeGlace;

	sf::Music musique;
	sf::SoundBuffer bufferCreationTour;
	sf::SoundBuffer bufferTirTourAttaqueBasique;
	sf::SoundBuffer bufferTirCanonLourd;

	sf::Font policeMenu;
	sf::Font policeTableauDeBord;
};

#endif /* RESOURCESLOADER_H_ */
