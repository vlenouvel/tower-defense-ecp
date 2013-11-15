/*
 * Etat.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef ETAT_H_
#define ETAT_H_

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

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
	virtual void update()=0;

protected:
	App* pApp;
};

#endif /* ETAT_H_ */
