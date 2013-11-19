/*
 * Etat.h
 *
 *  TowerDefense ECP
 *       
 */

#ifndef ETAT_H_
#define ETAT_H_

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "../ResourcesLoader.h"

class App;
class Etat {
public:
	Etat(App* tApp);
	virtual ~Etat();
	virtual void init();
	virtual void pause();
	virtual void resume();
	virtual void handleEvent(sf::Event event);
	virtual void agir(void);
	virtual void dessiner(sf::RenderWindow &pWindow);
protected:
	App* pApp;
};

#endif /* ETAT_H_ */
