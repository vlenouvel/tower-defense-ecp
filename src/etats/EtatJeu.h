/*
 * EtatJeu.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef ETATJEU_H_
#define ETATJEU_H_


#include "Etat.h"
#include <string>
#include <cmath>
#include "SFML/Window/Event.hpp"
#include "../elements/Carte.h"
#include "../App.h"
#include "../ResourceManager.h"
#include "../elements/Ressources.h"
#include "../elements/TableauDeBord.h"
#include "../elements/Personnage.h"
#include "../elements/GenerateurVague.h"
#include "../elements/Batiments/TourAttaqueBasique.h"
#include "../elements/Batiments/CanonLourd.h"
#include "../elements/Batiments/TourDeGlace.h"
#include "../elements/Batiments/Mur.h"
#include "../elements/Batiments/TourSupport.h"
#include "EtatMort.h"

class EtatJeu: public Etat {
public:

	EtatJeu(App* tApp);
	virtual ~EtatJeu();
	void handleEvent(sf::Event event);
	void dessiner(sf::RenderWindow &pWindow);
	void agir();
	void setErreur(std::string err);
	Carte* carte;
	Ressources* pRessources;
	TableauDeBord* pTableauDeBord;

private:
	void construireBatiment(TableauDeBord::typeBatiment type, Coordonnees coord);
	void recalculerPathfinding();
	TableauDeBord::typeBatiment batimentChoisi;
	App* pApp;
	sf::RectangleShape arriveCase;
	std::string erreur;
	sf::Time tempsErreur;
	sf::Text texteErreur;
	sf::Font font;
	sf::Time tempsDisparitionErreur;
};

#endif /* ETATJEU_H_ */
