/*
 * EtatMenu.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef ETATMENU_H_
#define ETATMENU_H_

#include "Etat.h"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../elements/Menu.h"
#include "EtatPropos.h"
#include "../App.h"

class EtatMenu: public Etat {
public:
	EtatMenu(App* tApp);
	void handleEvent(sf::Event event);
	void dessiner(sf::RenderWindow &pWindow);
	virtual ~EtatMenu();
	void update();
	Menu* menu;
};

#endif /* ETATMENU_H_ */
