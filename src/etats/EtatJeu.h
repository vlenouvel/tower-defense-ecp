/*
 * EtatJeu.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
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


class EtatJeu: public Etat {
public:
	EtatJeu(App* tApp);
	virtual ~EtatJeu();
	void handleEvent(sf::Event event);
	void dessiner(sf::RenderWindow &pWindow);
	Carte* carte;
	Ressources* pRessources;
	int typeTourChoisi;
	TableauDeBord* pTableauDeBord;


};

#endif /* ETATJEU_H_ */
