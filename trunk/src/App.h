/*
 * App.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Vincent Lenouvel
 */

#ifndef APP_H_
#define APP_H_
#include "elements/Menu.h"
#include "elements/Carte.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class App {
public:
	int etat;
	bool running;
	App();
	bool isRunning();
	void boucle();
	void render();
	void update();
	void gererEvents();
	virtual ~App();

private:
	sf::RenderWindow window;


	//sf::RenderWindow &pWindow;
};

#endif /* APP_H_ */
