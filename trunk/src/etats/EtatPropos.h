/*
 * EtatPropos.h
 *
 */

#ifndef ETATPROPOS_H_
#define ETATPROPOS_H_

#include "Etat.h"
#include <sstream>
#include "EtatMenu.h"

class EtatPropos: public Etat {
public:
	EtatPropos(App *tApp);
	void handleEvent(sf::Event event);
	void dessiner(sf::RenderWindow &pWindow);
	void agir();
	virtual ~EtatPropos();

private:
	sf::Text text;
	sf::Font font;
};

#endif /* ETATPROPOS_H_ */
