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
	Carte* carte;
	Ressources* pRessources;
	// cet entier nous dit quel type de tour on cree, c'est sale donc a changer
	int typeTourChoisi;
	TableauDeBord* pTableauDeBord;
	Personnage * pPersonnage;
private:
	App* pApp;
	sf::RectangleShape arriveCase;

};

#endif /* ETATJEU_H_ */
