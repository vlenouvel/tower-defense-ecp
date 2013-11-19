/*
 * EtatChargement.h
 *
 *  Created on: 18 nov. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef ETATCHARGEMENT_H_
#define ETATCHARGEMENT_H_

#include "Etat.h"
#include "../App.h"

class EtatChargement: public Etat {
public:
	EtatChargement(App *tApp);
	void handleEvent(sf::Event event);
	void dessiner(sf::RenderWindow &pWindow);
	void agir();
	virtual ~EtatChargement();

private:
	enum Etape {RIEN, POLICES, TEXTURES, SONS};
	Etape etape;
	bool keepLoading;
	sf::Font fontLoading;
	sf::Text textLoading;
	sf::Clock clockLoading;
	sf::Time tempsMinimum;
};

#endif /* ETATCHARGEMENT_H_ */
