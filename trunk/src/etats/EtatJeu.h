/*
 * EtatJeu.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef ETATJEU_H_
#define ETATJEU_H_


#include "Etat.h"
#include "SFML/Window/Event.hpp"
#include "../elements/Carte.h"
#include "../App.h"
#include "../ResourceManager.h"
#include "../elements/Ressources.h"
#include <iostream>
#include <string>
#include "../elements/TableauDeBord.h"
#include "../elements/Personnage.h"
#include "../elements/GenerateurVague.h"
#include "../elements/TourAttaqueBasique.h"
#include "../elements/CanonLourd.h"


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
	// cet entier nous dit quel type de tour on cree, c'est sale donc a changer
	int typeTourChoisi;
	TableauDeBord* pTableauDeBord;

private:
	App* pApp;
	sf::RectangleShape arriveCase;
	std::string erreur;
	sf::Time tempsErreur;
	sf::Text texteErreur;
	sf::Font font;
	sf::Time tempsDisparitionErreur;
};

#endif /* ETATJEU_H_ */
