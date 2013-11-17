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

	sf::Music musique;
	sf::SoundBuffer bufferCreationTour;
	sf::SoundBuffer bufferTirTourAttaqueBasique;
	sf::SoundBuffer bufferTirCanonLourd;

	sf::Font police;
};

#endif /* RESOURCESLOADER_H_ */
