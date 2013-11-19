/*
 * ResourcesLoader.h
 *
 *  TowerDefense ECP
 *      
 */

#ifndef RESOURCESLOADER_H_
#define RESOURCESLOADER_H_
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


/* Cette classe est destinee a charger tout ce qui est dans le dossier resources, c'est-a-dire la police, les sons et les textures.
Les objets crees par la suite viennent chercher ce dont ils ont besoin dans cette fonction.*/

class ResourcesLoader {
public:
	ResourcesLoader();
	virtual ~ResourcesLoader();

	static ResourcesLoader* getInstance();

	void ChargerTextures();
	void ChargerSons();
	void ChargerPolices();

	sf::Texture texturePersonnage;
	sf::Texture textureCarte;
	sf::Texture textureCanonLourd;
	sf::Texture textureTourAttaqueBasique;
	sf::Texture textureProjectileBasique;
	sf::Texture textureProjectileExplosif;
	sf::Texture textureRessources;
	sf::Texture textureLevelUpBouton;
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

	sf::Music musique;
	sf::SoundBuffer bufferCreationTour;
	sf::SoundBuffer bufferTirTourAttaqueBasique;
	sf::SoundBuffer bufferTirCanonLourd;

	sf::Font policeMenu;
	sf::Font policeTableauDeBord;
};

#endif /* RESOURCESLOADER_H_ */
